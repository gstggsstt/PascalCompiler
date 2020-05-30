//
// Created by gster on 5/23/20.
//

#include <iostream>
#include "ASTNode.h"

std::string getTypeName(llvm::Type *type){
    return "";
}

llvm::Constant* getInitial(llvm::Type* type, ConstValue* value){
	if(type->isDoubleTy()){
		return llvm::ConstantFP::get(builder.getDoubleTy(), dynamic_cast<ConstRealValue*>(value)->val);
	}else if(type->isIntegerTy(64)){
		return builder.getInt64(dynamic_cast<ConstIntValue*>(value)->val);
	}else if(type->isIntegerTy(8)){
		return builder.getInt8(dynamic_cast<ConstCharValue*>(value)->val);
	}else{
		std::cerr<< "no initializer for '"+getTypeName(type)+"'"<<std::endl;
		return nullptr;
	}
}

llvm::Constant* getInitial(llvm::Type* type){
	if(type->isDoubleTy()){
		return llvm::ConstantFP::get(builder.getDoubleTy(), 0);
	}else if(type->isIntegerTy(64)){
		return builder.getInt64(0);
	}else if(type->isIntegerTy(8)){
		return builder.getInt8(0);
	}else{
		std::cerr<< "no initializer for '"+getTypeName(type)+"'"<<std::endl;
		return nullptr;
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
		errorMsg = "no viable conversion from '"+getTypeName(valType)
					  +"' to '"+getTypeName(type)+"'";
		return nullptr;
	}
}//Used to Change llvm::Type when calculate exp;Change type of value to dest type;

Program::Program(ProgramHead *ph, Routine *rt) : ph(ph), rt(rt) {}

llvm::Value *Program::codeGen(ASTContext &astcontext){
	llvm::FunctionType* initFuncType = llvm::FunctionType::get(builder.getVoidTy(), false);
	llvm::Function* initFunc = llvm::Function::Create(initFuncType, llvm::Function::ExternalLinkage, "main", &module);
	builder.SetInsertPoint(llvm::BasicBlock::Create(context, "entry", initFunc));
	ph->codeGen(astcontext);
	rt->codeGen(astcontext);

	ASTFunction* mainFunc = astcontext.getFunction("main");
	if(mainFunc == nullptr){
		std::cout << errorMsg << std::endl;
	}else{
		builder.CreateCall(mainFunc->llvmFunction);
		builder.CreateRetVoid();
	}

	startFunc = initFunc;
	return nullptr;
}

ProgramHead::ProgramHead(std::string nm) : nm(nm) {}

llvm::Value *ProgramHead::codeGen(ASTContext &astcontext){
	return nullptr;
}

Routine::Routine(RoutineHead *rh, RoutineBody *rb) : rh(rh), rb(rb) {}

llvm::Value *Routine::codeGen(ASTContext &astcontext){
	rh->codeGen(astcontext);
	rb->codeGen(astcontext);
	return nullptr;
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
	return nullptr;
}

ConstPart::ConstPart(ConstExprList *cel) : cel(cel) {}

llvm::Value *ConstPart::codeGen(ASTContext& astcontext){
	return cel->codeGen(astcontext);
}

ConstExprList::ConstExprList() {}

void ConstExprList::pushBack(ConstValueDecl *ce) {
    vec.push_back(ce);
}

llvm::Value *ConstExprList::codeGen(ASTContext& astcontext){
	for(auto i = 0; i < vec.size(); i++){
		llvm::Type* type = astcontext.getType(vec[i]->value->typeName);
		if(type == nullptr){
			return nullptr;
		}
		llvm::Constant* initial = getInitial(type, vec[i]->value);
		llvm::Value* var = new llvm::GlobalVariable(module, type, false, llvm::GlobalValue::ExternalLinkage, initial);
		astcontext.addVar(vec[i]->name, var);
		/*var = astcontext.getVar(vec[i]->name);
		Value* v = vec[i]->value.codeGen(astcontext);
		v = createCast(v, type);
		if(v == nullptr){
			return ;
		}
		builder.CreateStore(v, var);*/
	}
	return nullptr;
}

ConstValueDecl::ConstValueDecl(const std::string &name, ConstValue *value) : name(name), value(value) {};

ConstIntValue::ConstIntValue(const std::string &val) : val(stoi(val)) {typeName = "int";};

ConstValue *ConstIntValue::setNeg() {
    val = -val;
    return this;
}

llvm::Value *ConstIntValue::codeGen(ASTContext &astContext) {
    return ConstValue::codeGen(astContext);
}

ConstRealValue::ConstRealValue(const std::string &val) : val(stof(val)) {typeName = "real";}

ConstValue *ConstRealValue::setNeg() {
    val = -val;
    return this;
}

llvm::Value *ConstRealValue::codeGen(ASTContext &astContext) {
    return ConstValue::codeGen(astContext);
}

ConstCharValue::ConstCharValue(const std::string &val) : val(val[1]) {typeName = "char";}

ConstValue *ConstCharValue::setNeg() {
    return this;
}

llvm::Value *ConstCharValue::codeGen(ASTContext &astContext) {
    return ConstValue::codeGen(astContext);
}

TypeDeclList::TypeDeclList() {}

void TypeDeclList::pushBack(TypeDefinition *td) {
    vec.push_back(td);
}

llvm::Value *TypeDeclList::codeGen(ASTContext &astContext) {
    return TypePart::codeGen(astContext);
}

SysType::SysType(const std::string &tp) : tp(tp) {}

llvm::Value *SysType::codeGen(ASTContext &astContext) {
    return SimpleType::codeGen(astContext);
}

CustomType::CustomType(std::string nm) : nm(nm) {}

llvm::Value *CustomType::codeGen(ASTContext &astContext) {
    return SimpleType::codeGen(astContext);
}

EnumType::EnumType(NameList *nl) : nl(nl) {}

llvm::Value *EnumType::codeGen(ASTContext &astContext) {
    return SimpleType::codeGen(astContext);
}

RangeType::RangeType(ConstValue *l, ConstValue *r) : l(l), r(r) {}

llvm::Value *RangeType::codeGen(ASTContext &astContext) {
    return SimpleType::codeGen(astContext);
}

ArrayType::ArrayType(SimpleType *st, TypeDecl *td) : st(st), td(td) {}

llvm::Value *ArrayType::codeGen(ASTContext &astContext) {
    return TypeDecl::codeGen(astContext);
}

RecordType::RecordType(FieldDeclList *fdl) : fdl(fdl) {}

llvm::Value *RecordType::codeGen(ASTContext &astContext) {
    return TypeDecl::codeGen(astContext);
}

FieldDeclList::FieldDeclList() {}

void FieldDeclList::pushBack(FieldDecl *fd) {
    vec.push_back(fd);
}

llvm::Value *FieldDeclList::codeGen(ASTContext &astContext) {
    return ASTNode::codeGen(astContext);
}

FieldDecl::FieldDecl(NameList *nl, TypeDecl *td) : nl(nl), td(td) {}

llvm::Value *FieldDecl::codeGen(ASTContext &astContext) {
    return ASTNode::codeGen(astContext);
}

void NameList::pushBack(std::string nm) {
    vec.push_back(nm);
}

NameList::NameList() {}

llvm::Value *NameList::codeGen(ASTContext &astContext) {
    return VarParaList::codeGen(astContext);
}

void VarDeclList::pushBack(VarDecl *vd) {
    vec.push_back(vd);
}

llvm::Value *VarDeclList::codeGen(ASTContext &astContext) {
    return VarPart::codeGen(astContext);
}

VarDecl::VarDecl(NameList *nl, TypeDecl *td) : nl(nl), td(td) {}

llvm::Value *VarDecl::codeGen(ASTContext &astContext) {
    return ASTNode::codeGen(astContext);
}

RoutinePart::RoutinePart() {}

void RoutinePart::pushBack(RoutineDecl *rd) {
    vec.push_back(rd);
}

llvm::Value *RoutinePart::codeGen(ASTContext &astContext) {
    return ASTNode::codeGen(astContext);
}

Function::Function(FunctionHead *fh, Routine *rt) : fh(fh), RoutineDecl(rt) {}

ParaDeclList::ParaDeclList() {}

void ParaDeclList::pushBack(ParaTypeList *ptl) {
    vec.push_back(ptl);
}

llvm::Value *ParaDeclList::codeGen(ASTContext &astContext) {
    return Parameters::codeGen(astContext);
}

ParaTypeList::ParaTypeList(VarParaList *vpl, SimpleType *st) : vpl(vpl), st(st) {}

llvm::Value *ParaTypeList::codeGen(ASTContext &astContext) {
    return ASTNode::codeGen(astContext);
}

void StmtList::pushBack(Stmt *st) {
    vec.push_back(st);
}

StmtList::StmtList() {}

llvm::Value *StmtList::codeGen(ASTContext &astContext) {
    return CompoundStmt::codeGen(astContext);
}

Stmt::Stmt(): label(0),hasLabel(false) {}

Stmt::Stmt(const std::string &str) {
    hasLabel=true;
    label=stoi(str);
}

llvm::Value *Stmt::codeGen(ASTContext &astContext) {
    return ASTNode::codeGen(astContext);
}

void Stmt::addLabel(std::string label) {
    llvm::Type* returnType;
    returnType = fh->st->codeGen(astContext);
    std::vector<llvm::Type*> argTypes;
}

NameLeftValue::NameLeftValue(std::string nm) : nm(nm) {}

IndexLeftValue::IndexLeftValue(std::string nm, Expression *expr) : nm(nm), expr(expr) {}

MemberLeftValue::MemberLeftValue(std::string nm1, std::string nm2) : nm1(nm1), nm2(nm2) {}

NameProcStmt::NameProcStmt(std::string nm) : nm(nm) {}

llvm::Value *NameProcStmt::codeGen(ASTContext &astContext) {
    return ProcStmt::codeGen(astContext);
}

CallProcStmt::CallProcStmt(std::string nm, ArgsList *al) : nm(nm), al(al) {}

llvm::Value *CallProcStmt::codeGen(ASTContext &astContext) {
    return ProcStmt::codeGen(astContext);
}

SysProcStmt::SysProcStmt(SysProc *sp) : sp(sp) {}

llvm::Value *SysProcStmt::codeGen(ASTContext &astContext) {
    return ProcStmt::codeGen(astContext);
}

SysCallProcStmt::SysCallProcStmt(SysProc *sp, ExpressionList *el) : sp(sp), el(el) {}

llvm::Value *SysCallProcStmt::codeGen(ASTContext &astContext) {
    return ProcStmt::codeGen(astContext);
}

ReadProcStmt::ReadProcStmt(Factor *f) : f(f) {}

llvm::Value *ReadProcStmt::codeGen(ASTContext &astContext) {
    return ProcStmt::codeGen(astContext);
}

AssignStmt::AssignStmt(LeftValue *lv, Expression *expr) : lv(lv), expr(expr) {}

SysProc::SysProc(std::string proc) : proc(std::move(proc)) {}

llvm::Value *SysProc::codeGen(ASTContext &astContext) {
    return ASTNode::codeGen(astContext);
}

ElseClause::ElseClause() : st(nullptr) {}

ElseClause::ElseClause(Stmt *st) : st(st) {}

llvm::Value *ElseClause::codeGen(ASTContext &astContext) {
    return ASTNode::codeGen(astContext);
}

IfStmt::IfStmt(Expression *expr, Stmt *st, ElseClause *ec) : expr(expr), st(st), ec(ec) {}

llvm::Value *IfStmt::codeGen(ASTContext &astContext) {
    return Stmt::codeGen(astContext);
}

WhileStmt::WhileStmt(Expression *expr, Stmt *st) : expr(expr), st(st) {}

llvm::Value *WhileStmt::codeGen(ASTContext &astContext) {
    return Stmt::codeGen(astContext);
}

Direction::Direction(std::string dir) : dir(std::move(dir)) {}

llvm::Value *Direction::codeGen(ASTContext &astContext) {
    return ASTNode::codeGen(astContext);
}

CaseStmt::CaseStmt(Expression *expr, CaseExprList *cel) : expr(expr), cel(cel) {}

llvm::Value *CaseStmt::codeGen(ASTContext &astContext) {
    return Stmt::codeGen(astContext);
}

void CaseExprList::pushBack(CaseExpr *ce) {
    vec.push_back(ce);
}

llvm::Value *CaseExprList::codeGen(ASTContext &astContext) {
    return ASTNode::codeGen(astContext);
}

CaseExprList::CaseExprList() = default;

CaseExpr::CaseExpr(Stmt *st) : st(st) {}

llvm::Value *CaseExpr::codeGen(ASTContext &astContext) {
    return ASTNode::codeGen(astContext);
}

ConstValueCaseExpr::ConstValueCaseExpr(ConstValue *cv, Stmt *st) : CaseExpr(st), cv(cv) {}

llvm::Value *ConstValueCaseExpr::codeGen(ASTContext &astContext) {
    return CaseExpr::codeGen(astContext);
}

NameCaseExpr::NameCaseExpr(std::string nm, Stmt *st) : CaseExpr(st), nm(nm) {}

llvm::Value *NameCaseExpr::codeGen(ASTContext &astContext) {
    return CaseExpr::codeGen(astContext);
}

GotoStmt::GotoStmt(const std::string& str) : label(stoi(str)) {}

llvm::Value *GotoStmt::codeGen(ASTContext &astContext) {
    return Stmt::codeGen(astContext);
}

void ExpressionList::pushBack(Expression *expr) {
    vec.push_back(expr);
}

ExpressionList::ExpressionList() {vec.clear();}

BinaryExpr::BinaryExpr(Expression *l, Expression *r, std::string op) : l(l), r(r), op(std::move(op)) {}

CalcExpr::CalcExpr(Expression *l, Expression *r, std::string op) : l(l), r(r), op(std::move(op)) {}

NameFactor::NameFactor(std::string nm) : nm(nm) {}

CallFactor::CallFactor(std::string nm, ArgsList *al) : nm(nm), al(al) {}

SysFuncFactor::SysFuncFactor(SysFunc *sf) : sf(sf) {}

llvm::Value *SysFuncFactor::codeGen(ASTContext &astContext) {
    return Factor::codeGen(astContext);
}

SysFuncCallFactor::SysFuncCallFactor(SysFunc *sf, ArgsList *al) : sf(sf), al(al) {}

ConstFactor::ConstFactor(ConstValue *cv) : cv(cv) {}

llvm::Value *ConstFactor::codeGen(ASTContext &astContext) {
    return Factor::codeGen(astContext);
}

ParenthesesFactor::ParenthesesFactor(Expression *expr) : expr(expr) {}

llvm::Value *ParenthesesFactor::codeGen(ASTContext &astContext) {
    return Factor::codeGen(astContext);
}

IndexFactor::IndexFactor(std::string nm, Expression *expr) : nm(nm), expr(expr) {}

llvm::Value *IndexFactor::codeGen(ASTContext &astContext) {
    return Factor::codeGen(astContext);
}

MemberFactor::MemberFactor(std::string nm1, std::string nm2) : nm1(nm1), nm2(nm2) {}

llvm::Value *MemberFactor::codeGen(ASTContext &astContext) {
    return Factor::codeGen(astContext);
}

Factor *Factor::setNot() {
    // TODO
    return this;
}

Factor *Factor::setNeg() {
    // TODO
    return this;
}

llvm::Value *Factor::codeGen(ASTContext &astContext) {
    return Term::codeGen(astContext);
}

SysFunc::SysFunc(std::string str) : str(std::move(str)) {}

llvm::Value *SysFunc::codeGen(ASTContext &astContext) {
    return ASTNode::codeGen(astContext);
}

void ArgsList::pushBack(Expression *expr) {
    vec.push_back(expr);
}

llvm::Value *ArgsList::codeGen(ASTContext &astContext) {
    return ASTNode::codeGen(astContext);
}

ArgsList::ArgsList() = default;

RoutineDecl::RoutineDecl(Routine *rt) : rt(rt) {}

llvm::Value *RoutineDecl::codeGen(ASTContext &astContext) {
    return ASTNode::codeGen(astContext);
}

Procedure::Procedure(ProcedureHead *ph, Routine *rt) : RoutineDecl(rt), ph(ph) {}

llvm::Value *Procedure::codeGen(ASTContext &astContext) {
    return RoutineDecl::codeGen(astContext);
}


//Fucntion Declaration
llvm::Value* Function::codeGen(ASTContext &astContext) {
    return nullptr;
}

llvm::Value* FunctionHead::codeGen(ASTContext &astContext) {
    return nullptr;
}

llvm::Type* SysType::codeGen(ASTContext &astContext) {
    return astContext.getType(tp);
}
//Assign
llvm::Value* AssignStmt::codeGen(ASTContext &astContext) {
    llvm::Value* var = lv->codeGen(astContext);
    if(var==NULL)
        std::cerr<<"No such Value"<<std::endl;
    else {
        llvm::Value* value = expr->codeGen(astContext);
        llvm::PointerType *pt = static_cast<llvm::PointerType*>(var->getType());
        value = createCast(value,pt->getElementType());
        if(value == NULL){
            std::cerr<<"Wrong Type Assignment"<<std::endl;
        }
        builder.CreateStore(value,var);
    }
    return NULL;
}

llvm::Value* LeftValue::codeGen(ASTContext &astContext) {
    return nullptr;
}

llvm::Value* NameLeftValue::codeGen(ASTContext &astContext) {
    llvm::Value* var = astContext.getVar(nm);
    if(var == nullptr) std::cerr<<"variable not declared"<<std::endl;
    return var;
}

llvm::Value* IndexLeftValue::codeGen(ASTContext &astContext) {
    return nullptr;
}

llvm::Value* MemberLeftValue::codeGen(ASTContext &astContext) {
    return nullptr;
}

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
    return nullptr;
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
    return nullptr;
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
    return nullptr;
}

llvm::Value* NameFactor::codeGen(ASTContext &astContext) {
	llvm::Value* var = astContext.getVar(nm);
	if(var == nullptr) std::cerr<<"variable not declared"<<std::endl;
	return builder.CreateLoad(var);
}

llvm::Value* CallFactor::codeGen(ASTContext &astContext) {
    ASTFunction* myfunc = astContext.getFunction(nm);
    if(myfunc==NULL) {
        std::cerr<<"No Function"<<std::endl;
    } else {
        std::vector<llvm::Type*> &argTypes = myfunc->argTypes;
        std::vector<llvm::Value*> exprListValues;
        std::vector<Expression*> &exprList = al->vec;
        for (int i = 0; i < exprList.size(); ++i) {
            Expression *expr = exprList[i];
            exprListValues.push_back(expr->codeGen(astContext));
        }
        if(exprListValues.size()<argTypes.size())
            std::cerr<<"Too Few Arguments"<<std::endl;
        else if(exprListValues.size()>argTypes.size())
            std::cerr<<"Too Many Arguments"<<std::endl;

        llvm::Value *callResult = NULL;
        if(argTypes.size() == 0){
            callResult = builder.CreateCall(myfunc->llvmFunction);
        }else{
            std::vector<llvm::Value*> argValues;
            for(unsigned i=0; i < argTypes.size(); i++){
                llvm::Value *v = createCast(exprListValues[i],argTypes[i]);
                if(v == NULL){
                  std::cerr<<"Wrong Type"<<std::endl;
                }
                argValues.push_back(v);
            }
            llvm::ArrayRef<llvm::Value*> args(argValues);
            callResult = builder.CreateCall(myfunc->llvmFunction,args);
        }

        llvm::Value* resultValue;
            llvm::Value *alloc = builder.CreateAlloca(myfunc->returnType);
            builder.CreateStore(callResult,alloc);
        return resultValue;
    }
    return nullptr;
}

llvm::Value* SysFuncCallFactor::codeGen(ASTContext &astContext) {
    return nullptr;
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

TypeDefinition::TypeDefinition(std::string nm, TypeDecl *td) : nm(nm), td(td) {}

llvm::Value *TypeDefinition::codeGen(ASTContext &astContext) {
    return ASTNode::codeGen(astContext);
}

NamedRangeType::NamedRangeType(std::string cv1, std::string cv2) : cv1(cv1), cv2(cv2) {}

llvm::Value *NamedRangeType::codeGen(ASTContext &astContext) {
    return SimpleType::codeGen(astContext);
}

FunctionHead::FunctionHead(const std::string &nm, Parameters *para, SimpleType *st) : nm(nm), para(para), st(st) {}

ProcedureHead::ProcedureHead(const std::string &nm, Parameters *para) : nm(nm), para(para) {}

llvm::Value *ProcedureHead::codeGen(ASTContext &astContext) {
    return ASTNode::codeGen(astContext);
}

RepeatStmt::RepeatStmt(StmtList *sl, Expression *expr) : sl(sl), expr(expr) {}

llvm::Value *RepeatStmt::codeGen(ASTContext &astContext) {
    return Stmt::codeGen(astContext);
}

ForStmt::ForStmt(const std::string &nm, Expression *expr, Direction *dir, Expression *toExpr, Stmt *st) : nm(nm),
                                                                                                          expr(expr),
                                                                                                          dir(dir),
                                                                                                          toExpr(toExpr),
                                                                                                          st(st) {}

llvm::Value *ForStmt::codeGen(ASTContext &astContext) {
    return Stmt::codeGen(astContext);
}

llvm::Value *ASTNode::codeGen(ASTContext &astContext) {
    return nullptr;
}

llvm::Value *ConstValue::codeGen(ASTContext &astContext) {
    return ASTNode::codeGen(astContext);
}

llvm::Value *Expr::codeGen(ASTContext &astContext) {
    return Expression::codeGen(astContext);
}

llvm::Value *Term::codeGen(ASTContext &astContext) {
    return Expr::codeGen(astContext);
}

llvm::Value *ProcStmt::codeGen(ASTContext &astContext) {
    return Stmt::codeGen(astContext);
}

llvm::Value *RoutineBody::codeGen(ASTContext &astContext) {
    return ASTNode::codeGen(astContext);
}

llvm::Value *CompoundStmt::codeGen(ASTContext &astContext) {
    return Stmt::codeGen(astContext);
}

llvm::Value *LabelPart::codeGen(ASTContext &astContext) {
    return ASTNode::codeGen(astContext);
}

llvm::Value *TypePart::codeGen(ASTContext &astContext) {
    return ASTNode::codeGen(astContext);
}

llvm::Value *VarPart::codeGen(ASTContext &astContext) {
    return ASTNode::codeGen(astContext);
}

llvm::Value *TypeDecl::codeGen(ASTContext &astContext) {
    return ASTNode::codeGen(astContext);
}

llvm::Value *Parameters::codeGen(ASTContext &astContext) {
    return ASTNode::codeGen(astContext);
}

llvm::Value *SimpleType::codeGen(ASTContext &astContext) {
    return TypeDecl::codeGen(astContext);
}

llvm::Value *VarParaList::codeGen(ASTContext &astContext) {
    return ASTNode::codeGen(astContext);
}

VarParaList::VarParaList() : ref(false) {}
