//
// Created by gster on 5/23/20.
//

#include <iostream>
#include <utility>
#include "ASTNode.h"

std::string getTypeName(llvm::Type *type){
    if(type->isDoubleTy()){
		return "real";
	}else if(type->isIntegerTy(64)){
		return "int";
	}if(type->isVoidTy()){
		return "void";
	}else if(type->isIntegerTy(8)){
        return "char";
    }else if(type->isIntegerTy(1)){
        return "bool";
    }else{
		return "unknow";
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
	if(valType == type ||
	    type->isDoubleTy() && valType->isDoubleTy() ||
	    type->isIntegerTy(64) && valType->isIntegerTy(64))
		return value;
	else if(type->isDoubleTy() && valType->isIntegerTy(64))
		return builder.CreateSIToFP(value,type);
	else if(type->isIntegerTy(64) && valType->isDoubleTy())
		return builder.CreateFPToSI(value,type);
	else{
		errorMsg = "no viable conversion from '"+getTypeName(valType)
					  +"' to '"+getTypeName(type)+"'";
		return nullptr;
	}
}//Used to Change llvm::Type when calculate exp;Change type of value to dest type;

Program::Program(ProgramHead *ph, Routine *rt) : ph(ph), rt(rt) {}

llvm::Value *Program::codeGen(ASTContext &astContext){
	llvm::FunctionType* funcType = llvm::FunctionType::get(builder.getVoidTy(), false);
	llvm::Function* llvmFunc = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "main", &module);
	builder.SetInsertPoint(llvm::BasicBlock::Create(context, "entry", llvmFunc));
	std::vector<llvm::Type*> argTypes;
    auto *mainFunc = new ASTFunction("main", llvmFunc, builder.getVoidTy(), argTypes);
    astContext.addFunction("main", mainFunc);
	astContext.currentFunction = mainFunc;

    ph->codeGen(astContext);
    rt->codeGen(astContext);

	if(mainFunc == nullptr){
		std::cout << errorMsg << std::endl;
	}else{
		builder.CreateCall(mainFunc->llvmFunction);
		builder.CreateRetVoid();
	}

	startFunc = llvmFunc;
    astContext.currentFunction->printIR();
	return nullptr;
}

ProgramHead::ProgramHead(std::string nm) : nm(std::move(nm)) {}

llvm::Value *ProgramHead::codeGen(ASTContext &astContext){
	return nullptr;
}

Routine::Routine(RoutineHead *rh, RoutineBody *rb) : rh(rh), rb(rb) {}

llvm::Value *Routine::codeGen(ASTContext &astContext){
	rh->codeGen(astContext);
	rb->codeGen(astContext);
	return nullptr;
}

RoutineHead::RoutineHead(LabelPart *lp, ConstPart *cp, TypePart *tp, VarPart *vp, RoutinePart *rp) : lp(lp), cp(cp),
                                                                                                     tp(tp), vp(vp),
                                                                                                     rp(rp) {}


llvm::Value *RoutineHead::codeGen(ASTContext &astContext){
	lp->codeGen(astContext);
	cp->codeGen(astContext);
	tp->codeGen(astContext);
	vp->codeGen(astContext);
	rp->codeGen(astContext);
	return nullptr;
}

ConstPart::ConstPart(ConstExprList *cel) : cel(cel) {}

llvm::Value *ConstPart::codeGen(ASTContext& astContext){
	return cel->codeGen(astContext);
}

ConstExprList::ConstExprList() = default;

void ConstExprList::pushBack(ConstValueDecl *ce) {
    vec.push_back(ce);
}

llvm::Value *ConstExprList::codeGen(ASTContext& astContext){
	for(auto & i : vec){
		llvm::Type* type = astContext.getType(i->value->typeName);
		if(type == nullptr){
			return nullptr;
		}
		llvm::Constant* initial = getInitial(type);
		llvm::Value* var = new llvm::GlobalVariable(module, type, false, llvm::GlobalValue::ExternalLinkage, initial);
		astContext.addVar(i->name, var);
		var = astContext.getVar(i->name);
		llvm::Value* v = i->value->codeGen(astContext);
		v = createCast(v, type);
		if(v == nullptr){
			return nullptr;
		}
		builder.CreateStore(v, var);
	}
	return nullptr;
}

ConstValueDecl::ConstValueDecl(std::string name, ConstValue *value) : name(std::move(name)), value(value) {}

llvm::Value *ConstValueDecl::codeGen(ASTContext &astContext) {
    return ASTNode::codeGen(astContext);
}

ConstIntValue::ConstIntValue(const std::string &val) : val(stoi(val)) {typeName = "int";}

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

TypeDeclList::TypeDeclList() = default;

void TypeDeclList::pushBack(TypeDefinition *td) {
    vec.push_back(td);
}

llvm::Value *TypeDeclList::codeGen(ASTContext &astContext) {
    for(auto & i : vec){
        i->codeGen(astContext);
    }
    return TypePart::codeGen(astContext);
}


llvm::Value *SysType::codeGen(ASTContext &astContext) {
    return SimpleType::codeGen(astContext);
}

SysType::SysType(const std::string &decltp) : SimpleType(decltp) {}

CustomType::CustomType(std::string nm, const std::string &decltp) : SimpleType(decltp), nm(std::move(nm)) {}

llvm::Value *CustomType::codeGen(ASTContext &astContext) {
    return SimpleType::codeGen(astContext);
}

EnumType::EnumType(NameList *nl, const std::string &decltp) : SimpleType(decltp), nl(nl) {}

llvm::Value *EnumType::codeGen(ASTContext &astContext) {
    return SimpleType::codeGen(astContext);
}

RangeType::RangeType(ConstValue *l, ConstValue *r, const std::string &decltp) : SimpleType(decltp), l(l), r(r) {}

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

FieldDeclList::FieldDeclList() = default;

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

void NameList::pushBack(const std::string& nm) {
    vec.push_back(nm);
}

NameList::NameList() = default;

llvm::Value *NameList::codeGen(ASTContext &astContext) {
    return VarParaList::codeGen(astContext);
}

void VarDeclList::pushBack(VarDecl *vd) {
    vec.push_back(vd);
}

llvm::Value *VarDeclList::codeGen(ASTContext &astContext) {
    for(auto & i : vec){
        i->codeGen(astContext);
    }
    return VarPart::codeGen(astContext);
}

VarDecl::VarDecl(NameList *nl, TypeDecl *td) : nl(nl), td(td) {}

llvm::Value *VarDecl::codeGen(ASTContext &astContext) {
    llvm::Type* type = astContext.getType(td->declTp);
    if(type == nullptr){
        return nullptr;
    }
    std::vector<std::string >& nv = nl->vec;
    for(auto & i : nv){
        llvm::Constant* initial = getInitial(type);
		llvm::Value* var = new llvm::GlobalVariable(module, type, false, llvm::GlobalValue::ExternalLinkage, initial);
		astContext.addVar(i, var);
    }
    return ASTNode::codeGen(astContext);
}

RoutinePart::RoutinePart() = default;

void RoutinePart::pushBack(RoutineDecl *rd) {
    vec.push_back(rd);
}

llvm::Value *RoutinePart::codeGen(ASTContext &astContext) {
    for(auto r : vec)
        r->codeGen(astContext);
    return nullptr;
}

Function::Function(FunctionHead *fh, Routine *rt) : fh(fh), RoutineDecl(rt) {}

ParaDeclList::ParaDeclList() = default;

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

StmtList::StmtList() = default;

llvm::Value *StmtList::codeGen(ASTContext &astContext) {
    for(auto stmt : vec)
        stmt->codeGen(astContext);
    return nullptr;
}

Stmt::Stmt(): label(0),hasLabel(false) {}

Stmt::Stmt(const std::string &str) {
    hasLabel=true;
    label=stoi(str);
}

llvm::Value *Stmt::codeGen(ASTContext &astContext) {
    return ASTNode::codeGen(astContext);
}

void Stmt::addLabel(const std::string &) {}

NameLeftValue::NameLeftValue(std::string nm) : nm(std::move(nm)) {}

IndexLeftValue::IndexLeftValue(std::string nm, Expression *expr) : nm(std::move(nm)), expr(expr) {}

MemberLeftValue::MemberLeftValue(std::string nm1, std::string nm2) : nm1(std::move(nm1)), nm2(std::move(nm2)) {}

NameProcStmt::NameProcStmt(std::string nm) : nm(std::move(nm)) {}

llvm::Value *NameProcStmt::codeGen(ASTContext &astContext) {
    return ProcStmt::codeGen(astContext);
}

CallProcStmt::CallProcStmt(std::string nm, ArgsList *al) : nm(std::move(nm)), al(al) {}

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
    llvm::Value* CondV = expr->codeGen(astContext);
    if(CondV == nullptr){
        return nullptr;
    }
    CondV = builder.CreateICmpNE(CondV, llvm::ConstantInt::get(builder.getInt64Ty(), 0), "ifcond");
    llvm::Function* TF = builder.GetInsertBlock()->getParent();
    llvm::BasicBlock* thenBB = llvm::BasicBlock::Create(context, "then", TF);
    llvm::BasicBlock* elseBB = llvm::BasicBlock::Create(context, "else");
    llvm::BasicBlock* mergeBB = llvm::BasicBlock::Create(context, "ifcond");
    builder.CreateCondBr(CondV, thenBB, elseBB);
    builder.SetInsertPoint(thenBB);
    llvm::Value* thenV = st->codeGen(astContext);
    if(thenV == nullptr){
        return nullptr;
    }
    builder.CreateBr(mergeBB);
    thenBB = builder.GetInsertBlock();
    TF->getBasicBlockList().push_back(elseBB);
    builder.SetInsertPoint(elseBB);
    llvm::Value* elseV = ec->codeGen(astContext);
    if(elseV == nullptr){
        return nullptr;
    }
    builder.CreateBr(mergeBB);
    elseBB = builder.GetInsertBlock();
    TF->getBasicBlockList().push_back(mergeBB);
    builder.SetInsertPoint(mergeBB);
    llvm::PHINode* PN = builder.CreatePHI(builder.getInt64Ty(), 2, "iftmp");

    PN->addIncoming(thenV, thenBB);
    PN->addIncoming(elseV, elseBB);
    return PN;
}

WhileStmt::WhileStmt(Expression *expr, Stmt *st) : expr(expr), st(st) {}

llvm::Value *WhileStmt::codeGen(ASTContext &astContext) {
    llvm::Function* TF = builder.GetInsertBlock()->getParent();
    llvm::BasicBlock* preBB = builder.GetInsertBlock();
    llvm::BasicBlock* loopBB = llvm::BasicBlock::Create(context, "loop", TF);
    builder.CreateBr(loopBB);
    builder.SetInsertPoint(loopBB);
    llvm::Value* condV = expr->codeGen(astContext);
    if(condV == 0){
        return 0;
    }
    condV = builder.CreateICmpNE(condV, llvm::ConstantInt::get(builder.getInt64Ty(), 0), "whilecond");
    llvm::BasicBlock* execBB = llvm::BasicBlock::Create(context, "exec");
    llvm::BasicBlock* afterBB = llvm::BasicBlock::Create(context, "after");
    builder.CreateCondBr(condV, execBB, afterBB);
    TF->getBasicBlockList().push_back(execBB);
    TF->getBasicBlockList().push_back(afterBB);
    builder.SetInsertPoint(execBB);
    llvm::Value* cd = st->codeGen(astContext);
    if(cd == nullptr){
        return nullptr;
    }
    builder.CreateBr(loopBB);
    builder.SetInsertPoint(afterBB);
    return llvm::Constant::getNullValue(builder.getInt64Ty());
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

NameCaseExpr::NameCaseExpr(std::string nm, Stmt *st) : CaseExpr(st), nm(std::move(nm)) {}

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

NameFactor::NameFactor(std::string nm) : nm(std::move(nm)) {}

llvm::Value* NameFactor::codeGen(ASTContext &astContext){
    llvm::Value* var = astContext.getVar(nm);
    llvm::Value* v = builder.CreateLoad(var);
    if(noT){
        builder.CreateNot(v);
    }
    if(neg){
        builder.CreateNeg(v);
    }
    return v;
}

CallFactor::CallFactor(std::string nm, ArgsList *al) : nm(std::move(nm)), al(al) {}

SysFuncFactor::SysFuncFactor(SysFunc *sf) : sf(sf) {}

llvm::Value *SysFuncFactor::codeGen(ASTContext &astContext) {
    return Factor::codeGen(astContext);
}

SysFuncCallFactor::SysFuncCallFactor(SysFunc *sf, ArgsList *al) : sf(sf), al(al) {}

ConstFactor::ConstFactor(ConstValue *cv) : cv(cv) {}

llvm::Value *ConstFactor::codeGen(ASTContext &astContext) {
    llvm::Value* v = cv->codeGen(astContext);
    if(noT){
        builder.CreateNot(v);
    }
    if(neg){
        builder.CreateNeg(v);
    }
    return v;
}

ParenthesesFactor::ParenthesesFactor(Expression *expr) : expr(expr) {}

llvm::Value *ParenthesesFactor::codeGen(ASTContext &astContext) {
    return Factor::codeGen(astContext);
}

IndexFactor::IndexFactor(std::string nm, Expression *expr) : nm(std::move(nm)), expr(expr) {}

llvm::Value *IndexFactor::codeGen(ASTContext &astContext) {
    return Factor::codeGen(astContext);
}

MemberFactor::MemberFactor(std::string nm1, std::string nm2) : nm1(std::move(nm1)), nm2(std::move(nm2)) {}

llvm::Value *MemberFactor::codeGen(ASTContext &astContext) {
    return Factor::codeGen(astContext);
}

Factor *Factor::setNot() {
    noT = !noT;
    return this;
}

Factor *Factor::setNeg() {
    neg = !neg;
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


//Function Declaration
llvm::Value* Function::codeGen(ASTContext &astContext) {
    ASTContext newContext(astContext);
    fh->codeGen(newContext);
    llvm::Function *llvmFunc = newContext.currentFunction->llvmFunction;
    llvm::BasicBlock *bb = llvm::BasicBlock::Create(context,"entry", llvmFunc);
    builder.SetInsertPoint(bb);
    rt->codeGen(newContext);
    builder.CreateRet(builder.CreateLoad(newContext.getVar(fh->nm)));
    llvm::verifyFunction(*llvmFunc);
    newContext.currentFunction->printIR();
    return nullptr;
}

llvm::Value* FunctionHead::codeGen(ASTContext &astContext) {
    std::vector<llvm::Type*> argType;
    for(const auto &i : dynamic_cast<ParaDeclList*>(para)->vec) {
        for(const auto &j : dynamic_cast<NameList*>(i->vpl)->vec){
            argType.push_back(astContext.getType(i->st->declTp));
            llvm::Value *var = builder.CreateAlloca(astContext.getType(i->st->declTp));
            astContext.addVar(j, var);
        }
    }
    llvm::ArrayRef<llvm::Type*> argTypeArrayRef;
    llvm::FunctionType *funcType = llvm::FunctionType::get(astContext.getType(st->declTp), argTypeArrayRef, false);
    llvm::Function *llvmFunc=llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, nm+"_sp", module);
    auto *func = new ASTFunction(nm, llvmFunc, astContext.getType(st->declTp), argType);
    astContext.addFunction(nm, func);
    llvm::Value *var = builder.CreateAlloca(astContext.getType((st->declTp)));
    astContext.addVar(func->name, var);
    astContext.currentFunction = func;
    return nullptr;
}

//Assign
llvm::Value* AssignStmt::codeGen(ASTContext &astContext) {
    llvm::Value* var = lv->codeGen(astContext);
    if(var==nullptr)
        std::cerr<<"No such Value"<<std::endl;
    else {
        llvm::Value* value = expr->codeGen(astContext);
        auto *pt = static_cast<llvm::PointerType*>(var->getType());
        value = createCast(value,pt->getElementType());
        if(value == nullptr){
            std::cerr<<"Wrong Type Assignment"<<std::endl;
        }
        builder.CreateStore(value,var);
    }
    return nullptr;
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
		}else{ // as int
			if(op==">=") {return builder.CreateICmpSGE(lv,rv);}
			else if(op==">") {return builder.CreateICmpSGT(lv,rv);}
			else if(op=="<=") {return builder.CreateICmpSLE(lv,rv);}
			else if(op=="<") {return builder.CreateICmpSLT(lv,rv);}
			else if(op=="=") {return builder.CreateICmpEQ(lv,rv);}
			else if(op=="<>") {return builder.CreateICmpNE(lv,rv);}
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
    if(myfunc==nullptr) {
        std::cerr<<"No Function"<<std::endl;
    } else {
        std::vector<llvm::Type*> &argTypes = myfunc->argTypes;
        std::vector<llvm::Value*> exprListValues;
        std::vector<Expression*> &exprList = al->vec;
        exprListValues.reserve(exprList.size());
        for (auto expr : exprList) {
            exprListValues.push_back(expr->codeGen(astContext));
        }
        if(exprListValues.size()<argTypes.size())
            std::cerr<<"Too Few Arguments"<<std::endl;
        else if(exprListValues.size()>argTypes.size())
            std::cerr<<"Too Many Arguments"<<std::endl;

        llvm::Value *callResult = nullptr;
        if(argTypes.empty()){
            callResult = builder.CreateCall(myfunc->llvmFunction);
        }else{
            std::vector<llvm::Value*> argValues;
            for(decltype(argTypes.size()) i=0; i < argTypes.size(); i++){
                llvm::Value *v = createCast(exprListValues[i],argTypes[i]);
                if(v == nullptr){
                  std::cerr<<"Wrong Type"<<std::endl;
                }
                argValues.push_back(v);
            }
            llvm::ArrayRef<llvm::Value*> args(argValues);
            callResult = builder.CreateCall(myfunc->llvmFunction,args);
        }

        llvm::Value *resultValue = nullptr;
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

ASTFunction::ASTFunction(std::string name, llvm::Function *llvmFunction, llvm::Type *returnType,
                         std::vector<llvm::Type *> &argTypes)
        :name(std::move(name)),llvmFunction(llvmFunction),returnType(returnType),argTypes(argTypes),returnVal(nullptr){
    returnType = llvmFunction->getReturnType();
}

void ASTFunction::printIR() const {
    const auto &vec = llvmFunction->getBasicBlockList();
    llvm::outs() << name << "\n";
    llvm::outs() << llvmFunction << "\n";
    for(const auto &b : vec){
        llvm::outs() << b << "\n";
    }
}

TypeDefinition::TypeDefinition(std::string nm, TypeDecl *td) : nm(std::move(nm)), td(td) {}

llvm::Value *TypeDefinition::codeGen(ASTContext &astContext) {
    if(td->declTp == "Custom"){
        llvm::Type* type = astContext.getType(dynamic_cast<CustomType*>(td)->nm);
        if(type == nullptr){
            return nullptr;
        }
        astContext.addType(nm, type);
    }else if(td->declTp == "bool"){
        astContext.addType(nm, astContext.getType("bool"));
    }else if(td->declTp == "real"){
        astContext.addType(nm, astContext.getType("real"));
    }else if(td->declTp == "char"){
        astContext.addType(nm, astContext.getType("char"));
    }else if(td->declTp == "int"){
        astContext.addType(nm, astContext.getType("int"));
    }
    return ASTNode::codeGen(astContext);
}

NamedRangeType::NamedRangeType(std::string cv1, std::string cv2, const std::string &decltp) : SimpleType(decltp),
                                                                                              cv1(std::move(cv1)), cv2(std::move(cv2)) {}

llvm::Value *NamedRangeType::codeGen(ASTContext &astContext) {
    return SimpleType::codeGen(astContext);
}

FunctionHead::FunctionHead(std::string nm, Parameters *para, SimpleType *st) : nm(std::move(nm)), para(para), st(st) {}

ProcedureHead::ProcedureHead(std::string nm, Parameters *para) : nm(std::move(nm)), para(para) {}

llvm::Value *ProcedureHead::codeGen(ASTContext &astContext) {
    return ASTNode::codeGen(astContext);
}

RepeatStmt::RepeatStmt(StmtList *sl, Expression *expr) : sl(sl), expr(expr) {}

llvm::Value *RepeatStmt::codeGen(ASTContext &astContext) {
    return Stmt::codeGen(astContext);
}

ForStmt::ForStmt(std::string nm, Expression *expr, Direction *dir, Expression *toExpr, Stmt *st) : nm(std::move(nm)),
                                                                                                          expr(expr),
                                                                                                          dir(dir),
                                                                                                          toExpr(toExpr),
                                                                                                          st(st) {}

llvm::Value *ForStmt::codeGen(ASTContext &astContext) {
    llvm::Value* var = astContext.getVar(nm);
    if(var == nullptr){
        return nullptr;
    }
    llvm::Value* begin = expr->codeGen(astContext);
    builder.CreateStore(begin, var);
    llvm::Function* TF = builder.GetInsertBlock()->getParent();
    llvm::BasicBlock* preBB = builder.GetInsertBlock();
    llvm::BasicBlock* loopBB = llvm::BasicBlock::Create(context, "loop", TF);
    builder.CreateBr(loopBB);
    llvm::PHINode* ph = builder.CreatePHI(builder.getInt64Ty(), 2, nm);
    llvm::Value* v = builder.CreateLoad(var);
    ph->addIncoming(v, preBB);
    if(st->codeGen(astContext) == nullptr){
        return nullptr;
    }
    llvm::Value* stepVal = llvm::ConstantInt::get(builder.getInt64Ty(), 1);
    llvm::Value* nextVal;
    if(dir->dir == "to"){
        nextVal = builder.CreateAdd(ph, stepVal, "nextvar");
    }else if(dir->dir == "downto"){
        nextVal = builder.CreateSub(ph, stepVal, "nextvar");
    }else{
        std::cerr << "direction " + dir->dir + " is not defied." << std::endl;
        return nullptr;
    }
    llvm::Value* endCond = toExpr->codeGen(astContext);
    if(endCond == nullptr){
        return nullptr;
    }
    endCond = builder.CreateICmpNE(endCond, llvm::ConstantInt::get(builder.getInt64Ty(), 0), "loopcond");
    llvm::BasicBlock* loopEndBB = builder.GetInsertBlock();
    llvm::BasicBlock* afterBB = llvm::BasicBlock::Create(context, "afterloop", TF);
    builder.CreateCondBr(endCond, loopBB, afterBB);
    builder.SetInsertPoint(afterBB);
    ph->addIncoming(nextVal, loopEndBB);
    return llvm::Constant::getNullValue(builder.getInt64Ty());
}

llvm::Value *ASTNode::codeGen(ASTContext &astContext) {
    return nullptr;
}

llvm::Value *ConstValue::codeGen(ASTContext &astContext) {
    if(typeName == "int"){
        return builder.getInt64(dynamic_cast<ConstIntValue*>(this)->val);
    }else if(typeName == "real"){
        return llvm::ConstantFP::get(builder.getDoubleTy(), dynamic_cast<ConstRealValue*>(this)->val);
    }else if(typeName == "char"){
        return builder.getInt8(dynamic_cast<ConstCharValue*>(this)->val);
    }
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
    return nullptr;
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

TypeDecl::TypeDecl(std::string decltp) : declTp(std::move(decltp)) {}

TypeDecl::TypeDecl() = default;

llvm::Value *Parameters::codeGen(ASTContext &astContext) {
    return ASTNode::codeGen(astContext);
}

llvm::Value *SimpleType::codeGen(ASTContext &astContext) {
    return TypeDecl::codeGen(astContext);
}

SimpleType::SimpleType(const std::string &decltp) : TypeDecl(decltp) {}

llvm::Value *VarParaList::codeGen(ASTContext &astContext) {
    return ASTNode::codeGen(astContext);
}

VarParaList::VarParaList() : ref(false) {}