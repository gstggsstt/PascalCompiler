//
// Created by gster on 5/23/20.
//

#include "ASTNode.h"


Value* createCast(Value *value,Type *type){
	Type *valType = value->getType();
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
		return NULL;
	}
}//Used to Change Type when calculate exp;Change type of value to dest type;

Program::Program(ProgramHead *ph, Routine *rt) : ph(ph), rt(rt) {}

ProgramHead::ProgramHead(Name *nm) : nm(nm) {}

Routine::Routine(RoutineHead *rh, RoutineBody *rb) : rh(rh), rb(rb) {}

RoutineHead::RoutineHead(LabelPart *lp, ConstPart *cp, TypePart *tp, VarPart *vp, RoutinePart *rp) : lp(lp), cp(cp),
                                                                                                     tp(tp), vp(vp),
                                                                                                     rp(rp) {}

ConstPart::ConstPart(ConstList *cel) : cel(cel) {}

ConstExprList::ConstExprList() {}

void ConstExprList::pushBack(ConstValue *ce) {
    vec.push_back(ce);
}

ConstIntValue::ConstIntValue(const std::string &val) : val(stoi(val)) {}

ConstValue *ConstIntValue::setNeg() {
    val = -val;
    return this;
}

ConstRealValue::ConstRealValue(const std::string &val) : val(stof(val)) {}

ConstValue *ConstRealValue::setNeg() {
    val = -val;
    return this;
}

ConstCharValue::ConstCharValue(const std::string &val) : val(val[0]) {}

ConstValue *ConstCharValue::setNeg() {
    return this;
}

TypeDeclList::TypeDeclList() {}

void TypeDeclList::pushBack(TypeDefinition *td) {
    vec.push_back(td);
}

SysType::SysType(const std::string &tp) : tp(tp) {}

CustomType::CustomType(Name *nm) : nm(nm) {}

EnumType::EnumType(NameList *nl) : nl(nl) {}

RangeType::RangeType(ConstValue *l, ConstValue *r) : l(l), r(r) {}

ArrayType::ArrayType(SimpleType *st, TypeDecl *td) : st(st), td(td) {}

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

Function::Function(FunctionHead *fh, Routine *rt) : fh(fh), RoutineDecl(rt) {}

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

SysProc::SysProc(const std::string &proc) : proc(proc) {}

ElseClause::ElseClause() : st(nullptr) {}

ElseClause::ElseClause(Stmt *st) : st(st) {}

IfStmt::IfStmt(Expression *expr, Stmt *st, ElseClause *ec) : expr(expr), st(st), ec(ec) {}

RepeatStmt::RepeatStmt(StmtList *sl, Stmt *st) : sl(sl), st(st) {}

WhileStmt::WhileStmt(Expression *expr, Stmt *st) : expr(expr), st(st) {}

ForStmt::ForStmt(Name *nm, Expression *expr, Direction *dir, Stmt *st) : nm(nm), expr(expr), dir(dir), st(st) {}

Direction::Direction(const std::string &dir) : dir(dir) {}

CaseStmt::CaseStmt(Expression *expr, CaseExprList *cel) : expr(expr), cel(cel) {}

void CaseExprList::pushBack(CaseExpr *ce) {
    vec.push_back(ce);
}

CaseExprList::CaseExprList() {}

CaseExpr::CaseExpr(Stmt *st) : st(st) {}

ConstValueCaseExpr::ConstValueCaseExpr(ConstValue *cv, Stmt *st) : CaseExpr(st), cv(cv) {}

NameCaseExpr::NameCaseExpr(Name *nm, Stmt *st) : CaseExpr(st), nm(nm) {}

GotoStmt::GotoStmt(std::string str) : label(stoi(str)) {}

void ExpressionList::pushBack(Expression *expr) {
    vec.push_back(expr);
}

ExpressionList::ExpressionList() {vec.clear();}

BinaryExpr::BinaryExpr(Expression *l, Expression *r, const std::string &op) : l(l), r(r), op(op) {}

CalcExpr::CalcExpr(Expression *l, Expression *r, const std::string &op) : l(l), r(r), op(op) {}

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

SysFunc::SysFunc(const std::string &str) : str(str) {}

void ArgsList::pushBack(Expression *expr) {
    vec.push_back(expr);
}

ArgsList::ArgsList() {}

Name::Name(const std::string &name) : name(name) {}

const std::string &Name::getName() const {
    return name;
}

RoutineDecl::RoutineDecl(Routine *rt) : rt(rt) {}

Procedure::Procedure(ProcedureHead *ph, Routine *rt) : RoutineDecl(rt), ph(ph) {}


///////////////////////////////////////////////////////
//Code Generate For ExpList and so on
Value* ExpressionList::codeGen(AstContext &astContext) {
	Value *last;
	for (int i = vec.size()-1; i>=0; --i)
	{
		last = vec[i]->codeGen();
	}
	return last;
}

Value* Expression::codeGen(ASTContext &astContext) {

}

Value* BinaryExpr::codeGen(ASTContext &astContext) {
	Value* lv = l->codeGen();
	Value* rv = r->codeGen();
	if( (lv->getType()->isDoubleTy() || lv->getType()->isIntegerTy(64) || lv->getType->isIntegerTy(8)) //only when both are int or double
		&& (rv->getType()->isDoubleTy() || rv->getType()->isIntegerTy(64)) || rv->getType->isIntegerTy(8)){
		if(op=="or") {
			return builder.CreateOr(lv,rv);
		} else {
			return builder.CreateAnd(lv,rv);
		}
	}else {
		cout<<"Wrong Type"<<endl;
	}
}

Value* CalcExpr::codeGen(ASTContext &astContext) {
	Value* lv = l->codeGen();
	Value* rv = r->codeGen();
	if( (lv->getType()->isDoubleTy() || lv->getType()->isIntegerTy(64)) //only when both are int or double
		&& (rv->getType()->isDoubleTy() || rv->getType()->isIntegerTy(64)) ){
		if(lv->getType()->isDoubleTy()){
			rv = createCast(rv,lv->getType());
		}else{
			lv = createCast(lv,rv->getType());
		}
		if(lv->getType()->isDoubleTy()){
			if(op==">=") {return builder.CreateFCmpOGE(lv,rv);}
			else if(op==">") {return builder.CreateFcmpOGT(lv,rv);}
			else if(op=="<=") {return builder.CreateFcmpOLE(lv,rv);}
			else if(op=="<") {return builder.CreateFcmpOLT(lv,rv);}
			else if(op=="=") {return builder.CreateFcmpOEQ(lv,rv);}
			else if(op=="<>") {return builder.CreateFcmpONE(lv,rv);}
			else if(op=="+") {return builder.CreateFAdd(lv,rv);}
			else if(op=="-") {return builder.CreateFSub(lv,rv);}
			else if(op=="*") {return builder.CreateFMul(lv,rv);}
			else if(op=="/") {return builder.CreateFDiv(lv,rv);}
			else if(op=="mod") {cout<<"Wrong Type"<<endl;}
			 // FIXME
		}else{
			if(op==">=") {return builder.CreateFCmpUGE(lv,rv);}
			else if(op==">") {return builder.CreateFcmpUGT(lv,rv);}
			else if(op=="<=") {return builder.CreateFcmpULE(lv,rv);}
			else if(op=="<") {return builder.CreateFcmpULT(lv,rv);}
			else if(op=="=") {return builder.CreateFcmpUEQ(lv,rv);}
			else if(op=="<>") {return builder.CreateFcmpUNE(lv,rv);}
			else if(op=="+") {return builder.CreateAdd(lv,rv);}
			else if(op=="-") {return builder.CreateSub(lv,rv);}
			else if(op=="*") {return builder.CreateMul(lv,rv);}
			else if(op=="/") {return builder.CreateDiv(lv,rv);}
			else if(op=="mod") {return builder.CreateFRem(lv,rv);}
		}
	}else {
		cout<<"Wrong Type"<<endl;
	}
}

Value* NameFactor::codeGen(ASTContext &astContext) {
	Value* var = astContext.getVar(nm->name);
	if(var == NULL) cout<<"variable not declared"<<endl;
	return builder.CreateLoad(var);
}

//////////////////////////////////////////////////////

Type* ASTContext::getType(string name){
	Type *type = typeTable[name];
	if(type == NULL && parent != NULL){
		type = parent->getType(name);
	}
	if(type == NULL){
		if(name == "void"){
			//errorMsg = "variable has incomplete type 'void'";
			cout<<"variable has incomplete type 'void'";
		}else{
			//errorMsg = "undeclared type '"+name+"'";
			cout<<"undeclared type '"<<name<<"'"
		}
	}
	return type;
}

AstFunction* ASTContext::getFunction(string name) throw(string){
	AstFunction *function = functionTable[name];
	if(function == NULL && parent != NULL){
		return parent->getFunction(name);
	}
	if(function == NULL){
		//errorMsg = "undeclared function '"+name+"'";
		cout<<"undeclared function '"<<name<<"'"<<endl;
	}
	return function;
}

Value* ASTContext::getVar(string name){
	Value *var = varTable[name];
	if(var == NULL && parent != NULL){
		return parent->getVar(name);
	}
	if(var == NULL){
		//errorMsg = "undeclared identifier '"+name+"'";
		cout<<"undeclared identifier '"<<name<<"'"<<endl;
	}
	return var;
}

bool ASTContext::addFunction(string name, AstFunction *function){
	if(functionTable[name] != NULL){
		//errorMsg = "redefine function named '"+name+"'";
		cout<<"redefine type named '"<<name<<"'"<<endl;
		return false;
	}
	functionTable[name] = function;
	return true;
}

bool ASTContext::addVar(string name, Value *value){
	if(varTable[name] != NULL){
		//errorMsg = "redefine variable named '"+name+"'";
		cout<<"redefine type named '"<<name<<"'"<<endl;
		return false;
	}
	varTable[name] = value;
	return true;
}

bool AstContext::addType(string name, Type *type){
	if(typeTable[name] != NULL){
		//errorMsg =  "redefine type named '"+name+"'";
		cout<<"redefine type named '"<<name<<"'"<<endl;
		return false;
	}
	typeTable[name] = type;
	return true;
}

