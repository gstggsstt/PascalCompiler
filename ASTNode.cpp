//
// Created by gster on 5/23/20.
//

#include <iostream>
#include "ASTNode.h"
#include <iostream>
using namespace std;
extern IRBuilder<> builder;
extern string errorMsg;
extern llvm::Module module;
extern llvm::LLVMContext context;
extern llvm::Function *startFunc = NULL;

string getTypeName(Type *type){

}

Constant* getInitial(Type* type, ConstValue* value){
	if(type->isDoubleTy()){
		return ConstantFP::get(builder.getDoubleTy(), dynamic_cast<ConstRealValue*>(value)->val);
	}else if(type->isIntegerTy(64)){
		return builder.getInt64(dynamic_cast<ConstIntValue*>(value)->val);
	}else if(type->isIntegerTy(8)){
		return builder.getInt8(dynamic_cast<ConstCharValue*>(value)->val);
	}else{
		errorMsg = "no initializer for '"+getTypeName(type)+"'";
		return NULL;
	}
}

Constant* getInitial(Type* type){
	if(type->isDoubleTy()){
		return ConstantFP::get(builder.getDoubleTy(), 0);
	}else if(type->isIntegerTy(64)){
		return builder.getInt64(0);
	}else if(type->isIntegerTy(8)){
		return builder.getInt8(0);
	}else{
		errorMsg = "no initializer for '"+getTypeName(type)+"'";
		return NULL;
	}
}

llvm::Value* createCast(llvm::Value *value,llvm::Type *type){
	llvm::Type *valType = value->getType();
	if(valType == type){
		return value;
	}else if(type->isDoubleTy() && valType->isDoubleTy()){
		return value;
	}else if(type->isIntegerTy(64) && valType->isIntegerTy(64)){
		return value;
	}else if(type->isDoubleTy() && valType->isIntegerTy(64)){
		return builder.CreateSIToFP(value,type);
	}else if(type->isIntegerTy(64) && valType->isDoubleTy()){
		return builder.CreateFPToSI(value,type);
	}else{
		string errorMsg = "no viable conversion from '"+getTypeName(valType)
					  +"' to '"+getTypeName(type)+"'";
		return nullptr;
	}
}//Used to Change llvm::Type when calculate exp;Change type of value to dest type;

Program::Program(ProgramHead *ph, Routine *rt) : ph(ph), rt(rt) {}

llvm::Value *Program::codeGen(ASTContext &astcontext){
	FunctionType* initFuncType = FunctionType::get(builder.getVoidTy(), false);
	llvm::Function* initFunc = llvm::Function::Create(initFuncType, llvm::Function::ExternalLinkage, "main", &module);
	builder.SetInsertPoint(BasicBlock::Create(context, "entry", initFunc));
	ph->codeGen(astcontext);
	rt->codeGen(astcontext);

	ASTFunction* mainFunc = astcontext.getFunction("main");
	if(mainFunc == NULL){
		cout << errorMsg << endl;
	}else{
		builder.CreateCall(mainFunc->llvmFunction);
		builder.CreateRetVoid();
	}

	startFunc = initFunc;
}

ProgramHead::ProgramHead(Name *nm) : nm(nm) {}

llvm::Value *ProgramHead::codeGen(ASTContext &astcontext){
	
}

Routine::Routine(RoutineHead *rh, RoutineBody *rb) : rh(rh), rb(rb) {}

llvm::Value *Routine::codeGen(ASTContext &astcontext){
	rh->codeGen(astcontext);
	rb->codeGen(astcontext);
}

RoutineHead::RoutineHead(LabelPart *lp, ConstPart *cp, TypePart *tp, VarPart *vp, RoutinePart *rp) : lp(lp), cp(cp),
                                                                                                     tp(tp), vp(vp),
                                                                                                     rp(rp) {}


llvm::Value *RoutineHead::codeGen(ASTContext &astcontext){
	lp->codeGen(astcontext);
	cp->codeGen(astcontext);
	tp->codeGen(astcontext);
	vp->codeGen(astcontext);
	rp->codeGen(astcontext);
}

llvm::Value *LabelPart::codeGen(ASTContext &astContext){

}

ConstPart::ConstPart(ConstExprList *cel) : cel(cel) {}

llvm::Value *ConstPart::codeGen(ASTContext& astcontext){
	cel->codeGen(astcontext);
}

ConstExprList::ConstExprList() {}

void ConstExprList::pushBack(ConstValueDecl *ce) {
    vec.push_back(ce);
}

llvm::Value *ConstExprList::codeGen(ASTContext& astcontext){
	for(auto i = 0; i < vec.size(); i++){
		Type* type = astcontext.getType(vec[i]->value.typeName);
		if(type == NULL){
			return ;
		}
		Constant* initial = getInitial(type, &vec[i]->value);
		Value* var = new GlobalVariable(module, type, false, GlobalValue::ExternalLinkage, initial);
		astcontext.addVar(vec[i]->name, var);
		/*var = astcontext.getVar(vec[i]->name);
		Value* v = vec[i]->value.codeGen(astcontext);
		v = createCast(v, type);
		if(v == NULL){
			return ;
		}
		builder.CreateStore(v, var);*/
	}
}

ConstValueDecl::ConstValueDecl(const std::string name, ConstValue& value) : name(name), value(value) {};

ConstIntValue::ConstIntValue(const std::string &val) : val(stoi(val)) {typeName = "int";};

ConstValue *ConstIntValue::setNeg() {
    val = -val;
    return this;
}

ConstRealValue::ConstRealValue(const std::string &val) : val(stof(val)) {typeName = "real";}

ConstValue *ConstRealValue::setNeg() {
    val = -val;
    return this;
}

ConstCharValue::ConstCharValue(const std::string &val) : val(val[1]) {typeName = "char";}

ConstValue *ConstCharValue::setNeg() {
    return this;
}

TypeDeclList::TypeDeclList() {}

void TypeDeclList::pushBack(TypeDefinition *td) {
    vec.push_back(td);
}

llvm::Value* TypeDeclList::codeGen(ASTContext& astcontext){
	for(auto i = 0; i < vec.size(); i++){
		
	}
}

SysType::SysType(const std::string &tp) : tp(tp) {}

CustomType::CustomType(Name *nm) : nm(nm) {}

EnumType::EnumType(NameList *nl) : nl(nl) {}

RangeType::RangeType(ConstValue *l, ConstValue *r) : l(l), r(r) {}

_ArrayType::_ArrayType(SimpleType *st, TypeDecl *td) : st(st), td(td) {}

RecordType::RecordType(FieldDeclList *fdl) : fdl(fdl) {}

FieldDeclList::FieldDeclList() {}

void FieldDeclList::pushBack(FieldDecl *fd) {
    vec.push_back(fd);
}

FieldDecl::FieldDecl(NameList *nl, TypeDecl *td) : nl(nl), td(td) {}

void NameList::pushBack(Name *nm) {
    vec.push_back(nm);
}

void VarDeclList::pushBack(VarDecl *vd) {
    vec.push_back(vd);
}

VarDecl::VarDecl(NameList *nl, TypeDecl *td) : nl(nl), td(td) {}

RoutinePart::RoutinePart() {}

void RoutinePart::pushBack(RoutineDecl *rd) {
    vec.push_back(rd);
}

_Function::_Function(FunctionHead *fh, Routine *rt) : fh(fh), RoutineDecl(rt) {}

FunctionHead::FunctionHead(Name *nm, Parameters *para) : nm(nm), para(para) {}

ParaDeclList::ParaDeclList() {}

void ParaDeclList::pushBack(ParaTypeList *ptl) {
    vec.push_back(ptl);
}

ParaTypeList::ParaTypeList(VarParaList *vpl, SimpleType *st) : vpl(vpl), st(st) {}

void StmtList::pushBack(Stmt *st) {
    vec.push_back(st);
}

StmtList::StmtList() {}

Stmt::Stmt(): label(0),hasLabel(false) {}

Stmt::Stmt(const std::string &str) {
    hasLabel=true;
    label=stoi(str);
}

NameLeftValue::NameLeftValue(Name *nm) : nm(nm) {}

IndexLeftValue::IndexLeftValue(Name *nm, Expression *expr) : nm(nm), expr(expr) {}

MemberLeftValue::MemberLeftValue(Name *nm1, Name *nm2) : nm1(nm1), nm2(nm2) {}

NameProcStmt::NameProcStmt(Name *nm) : nm(nm) {}

CallProcStmt::CallProcStmt(Name *nm, ArgsList *al) : nm(nm), al(al) {}

SysProcStmt::SysProcStmt(SysProc *sp) : sp(sp) {}

SysCallProcStmt::SysCallProcStmt(SysProc *sp, ExpressionList *el) : sp(sp), el(el) {}

ReadProcStmt::ReadProcStmt(Factor *f) : f(f) {}

AssignStmt::AssignStmt(LeftValue *lv, Expression *expr) : lv(lv), expr(expr) {}

SysProc::SysProc(std::string proc) : proc(std::move(proc)) {}

ElseClause::ElseClause() : st(nullptr) {}

ElseClause::ElseClause(Stmt *st) : st(st) {}

IfStmt::IfStmt(Expression *expr, Stmt *st, ElseClause *ec) : expr(expr), st(st), ec(ec) {}

RepeatStmt::RepeatStmt(StmtList *sl, Stmt *st) : sl(sl), st(st) {}

WhileStmt::WhileStmt(Expression *expr, Stmt *st) : expr(expr), st(st) {}

ForStmt::ForStmt(Name *nm, Expression *expr, Direction *dir, Stmt *st) : nm(nm), expr(expr), dir(dir), st(st) {}

Direction::Direction(std::string dir) : dir(std::move(dir)) {}

CaseStmt::CaseStmt(Expression *expr, CaseExprList *cel) : expr(expr), cel(cel) {}

void CaseExprList::pushBack(CaseExpr *ce) {
    vec.push_back(ce);
}

CaseExprList::CaseExprList() = default;

CaseExpr::CaseExpr(Stmt *st) : st(st) {}

ConstValueCaseExpr::ConstValueCaseExpr(ConstValue *cv, Stmt *st) : CaseExpr(st), cv(cv) {}

NameCaseExpr::NameCaseExpr(Name *nm, Stmt *st) : CaseExpr(st), nm(nm) {}

GotoStmt::GotoStmt(const std::string& str) : label(stoi(str)) {}

void ExpressionList::pushBack(Expression *expr) {
    vec.push_back(expr);
}

ExpressionList::ExpressionList() {vec.clear();}

BinaryExpr::BinaryExpr(Expression *l, Expression *r, std::string op) : l(l), r(r), op(std::move(op)) {}

CalcExpr::CalcExpr(Expression *l, Expression *r, std::string op) : l(l), r(r), op(std::move(op)) {}

NameFactor::NameFactor(Name *nm) : nm(nm) {}

CallFactor::CallFactor(Name *nm, ArgsList *al) : nm(nm), al(al) {}

SysFuncFactor::SysFuncFactor(SysFunc *sf) : sf(sf) {}

SysFuncCallFactor::SysFuncCallFactor(SysFunc *sf, ArgsList *al) : sf(sf), al(al) {}

ConstFactor::ConstFactor(ConstValue *cv) : cv(cv) {}

ParenthesesFactor::ParenthesesFactor(Expression *expr) : expr(expr) {}

IndexFactor::IndexFactor(Name *nm, Expression *expr) : nm(nm), expr(expr) {}

MemberFactor::MemberFactor(Name *nm1, Name *nm2) : nm1(nm1), nm2(nm2) {}

Factor *Factor::setNot() {
    // TODO
    return this;
}

Factor *Factor::setNeg() {
    // TODO
    return this;
}

SysFunc::SysFunc(std::string str) : str(std::move(str)) {}

void ArgsList::pushBack(Expression *expr) {
    vec.push_back(expr);
}

ArgsList::ArgsList() = default;

Name::Name(std::string name) : name(std::move(name)) {}

const std::string &Name::getName() const {
    return name;
}

RoutineDecl::RoutineDecl(Routine *rt) : rt(rt) {}

Procedure::Procedure(ProcedureHead *ph, Routine *rt) : RoutineDecl(rt), ph(ph) {}


///////////////////////////////////////////////////////
//Code Generate For ExpList and so on
llvm::Value* ExpressionList::codeGen(ASTContext &astContext) {
	llvm::Value *last;
	for (auto i = vec.size()-1; i>=0; --i)
	{
		last = vec[i]->codeGen(astContext);
	}
	return last;
}

llvm::Value* Expression::codeGen(ASTContext &astContext) {

}

llvm::Value* BinaryExpr::codeGen(ASTContext &astContext) {
	llvm::Value* lv = l->codeGen(astContext);
	llvm::Value* rv = r->codeGen(astContext);
	if( (lv->getType()->isDoubleTy() || lv->getType()->isIntegerTy(64) || lv->getType()->isIntegerTy(8)) //only when both are int or double
		&& (rv->getType()->isDoubleTy() || rv->getType()->isIntegerTy(64)) || rv->getType()->isIntegerTy(8)){
		if(op=="or") {
			return builder.CreateOr(lv,rv);
		} else {
			return builder.CreateAnd(lv,rv);
		}
	}else {
		std::cerr<<"Wrong llvm::Type"<<std::endl;
	}
}

llvm::Value* CalcExpr::codeGen(ASTContext &astContext) {
	llvm::Value* lv = l->codeGen(astContext);
	llvm::Value* rv = r->codeGen(astContext);
	if( (lv->getType()->isDoubleTy() || lv->getType()->isIntegerTy(64)) //only when both are int or double
		&& (rv->getType()->isDoubleTy() || rv->getType()->isIntegerTy(64)) ){
		if(lv->getType()->isDoubleTy()){
			rv = createCast(rv,lv->getType());
		}else{
			lv = createCast(lv,rv->getType());
		}
		if(lv->getType()->isDoubleTy()){ // as double
			if(op==">=") {return builder.CreateFCmpOGE(lv,rv);}
			else if(op==">") {return builder.CreateFCmpOGT(lv,rv);}
			else if(op=="<=") {return builder.CreateFCmpOLE(lv,rv);}
			else if(op=="<") {return builder.CreateFCmpOLT(lv,rv);}
			else if(op=="=") {return builder.CreateFCmpOEQ(lv,rv);}
			else if(op=="<>") {return builder.CreateFCmpONE(lv,rv);}
			else if(op=="+") {return builder.CreateFAdd(lv,rv);}
			else if(op=="-") {return builder.CreateFSub(lv,rv);}
			else if(op=="*") {return builder.CreateFMul(lv,rv);}
			else if(op=="/") {return builder.CreateFDiv(lv,rv);}
			else if(op=="mod") {std::cerr<<"Wrong llvm::Type"<<std::endl;}
			 // FIXME
		}else{ // as int
			if(op==">=") {return builder.CreateFCmpUGE(lv,rv);}
			else if(op==">") {return builder.CreateFCmpUGT(lv,rv);}
			else if(op=="<=") {return builder.CreateFCmpULE(lv,rv);}
			else if(op=="<") {return builder.CreateFCmpULT(lv,rv);}
			else if(op=="=") {return builder.CreateFCmpUEQ(lv,rv);}
			else if(op=="<>") {return builder.CreateFCmpUNE(lv,rv);}
			else if(op=="+") {return builder.CreateAdd(lv,rv);}
			else if(op=="-") {return builder.CreateSub(lv,rv);}
			else if(op=="*") {return builder.CreateMul(lv,rv);}
			else if(op=="/") {return builder.CreateSDiv(lv,rv);}
			else if(op=="mod") {return builder.CreateFRem(lv,rv);}
		}
	}else {
		std::cerr<<"Wrong llvm::Type"<<std::endl;
	}
}

llvm::Value* NameFactor::codeGen(ASTContext &astContext) {
	llvm::Value* var = astContext.getVar(nm->name);
	if(var == nullptr) std::cerr<<"variable not declared"<<std::endl;
	return builder.CreateLoad(var);
}

llvm::Type* ASTContext::getType(const std::string &name){
	llvm::Type *type = typeTable[name];
	if(type == nullptr && parent != nullptr){
		type = parent->getType(name);
	}
	if(type == nullptr){
		if(name == "void"){
			//errorMsg = "variable has incomplete type 'void'";
			std::cerr<<"variable has incomplete type 'void'" << std::endl;
		}else{
			//errorMsg = "undeclared type '"+name+"'";
			std::cerr<<"undeclared type '"<<name<<"'" << std::endl;
		}
	}
	return type;
}

ASTFunction* ASTContext::getFunction(const std::string &name) {
	ASTFunction *function = functionTable[name];
	if(function == nullptr && parent != nullptr){
		return parent->getFunction(name);
	}
	if(function == nullptr){
		//errorMsg = "undeclared function '"+name+"'";
		std::cerr<<"undeclared function '"<<name<<"'"<<std::endl;
	}
	return function;
}

llvm::Value* ASTContext::getVar(const std::string &name){
	llvm::Value *var = varTable[name];
	if(var == nullptr && parent != nullptr){
		return parent->getVar(name);
	}
	if(var == nullptr){
		//errorMsg = "undeclared identifier '"+name+"'";
		std::cerr<<"undeclared identifier '"<<name<<"'"<<std::endl;
	}
	return var;
}

bool ASTContext::addFunction(const std::string &name, ASTFunction *function){
	if(functionTable[name]){
		//errorMsg = "redefine function named '"+name+"'";
		std::cerr<<"redefine type named '"<<name<<"'"<<std::endl;
		return false;
	}
	functionTable[name] = function;
	return true;
}

bool ASTContext::addVar(const std::string &name, llvm::Value *value){
	if(varTable[name]){
		//errorMsg = "redefine variable named '"+name+"'";
		std::cerr<<"redefine type named '"<<name<<"'"<<std::endl;
		return false;
	}
	varTable[name] = value;
	return true;
}

bool ASTContext::addType(const std::string &name, llvm::Type *type){
	if(typeTable[name]){
		//errorMsg =  "redefine type named '"+name+"'";
		std::cerr<<"redefine type named '"<<name<<"'"<<std::endl;
		return false;
	}
	typeTable[name] = type;
	return true;
}

ASTFunction::ASTFunction(const std::string &name, llvm::Function *llvmFunction, llvm::Type *returnType,
                         std::vector<llvm::Type *> &argTypes)
        :name(name),llvmFunction(llvmFunction),returnType(returnType),argTypes(argTypes),returnVal(nullptr){
    returnType = llvmFunction->getReturnType();
}
