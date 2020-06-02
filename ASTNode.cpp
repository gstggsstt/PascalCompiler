//
// Created by gster on 5/23/20.
//

#include <iostream>
#include <utility>
#include "ASTNode.h"
#include "Utility.h"

llvm::Constant *getInitial(llvm::Type *type) {
    if (type->isDoubleTy()) {
        return llvm::ConstantFP::get(builder.getDoubleTy(), 0);
    } else if (type->isIntegerTy(64)) {
        return builder.getInt64(0);
    } else if (type->isIntegerTy(8)) {
        return builder.getInt8(0);
    } else {
        std::cerr << "no initializer for '" + ASTUtilitiy::getTypeName(type) + "'" << std::endl;
        return nullptr;
    }
}

Program::Program(ProgramHead *ph, Routine *rt) : ph(ph), rt(rt) {}

llvm::Value *Program::codeGen(ASTContext &astContext) {
    llvm::FunctionType *funcType = llvm::FunctionType::get(builder.getVoidTy(), false);
    llvm::Function *llvmFunc = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "main", &module);
    std::vector<llvm::Type *> argTypes;
    auto *mainFunc = new ASTFunction("main", llvmFunc, builder.getVoidTy(), argTypes);
    astContext.addFunction("main", mainFunc);
    astContext.currentFunction = mainFunc;
    startFunc = mainFunc->llvmFunction;
    ASTUtilitiy::startBlock(astContext);

    ph->codeGen(astContext);
    rt->codeGen(astContext);

    builder.CreateRetVoid();
    startFunc = llvmFunc;
    return nullptr;
}

ProgramHead::ProgramHead(std::string nm) : nm(std::move(nm)) {}

llvm::Value *ProgramHead::codeGen(ASTContext &astContext) {
    return nullptr;
}

Routine::Routine(RoutineHead *rh, RoutineBody *rb) : rh(rh), rb(rb) {}

llvm::Value *Routine::codeGen(ASTContext &astContext) {
    rh->codeGen(astContext);
    rb->codeGen(astContext);
    llvm::verifyFunction(*(astContext.currentFunction->llvmFunction));
    return nullptr;
}

RoutineHead::RoutineHead(LabelPart *lp, ConstPart *cp, TypePart *tp, VarPart *vp, RoutinePart *rp) : lp(lp), cp(cp),
                                                                                                     tp(tp), vp(vp),
                                                                                                     rp(rp) {}


llvm::Value *RoutineHead::codeGen(ASTContext &astContext) {
    lp->codeGen(astContext);
    cp->codeGen(astContext);
    tp->codeGen(astContext);
    vp->codeGen(astContext);
    auto tempBB = builder.GetInsertBlock();
    rp->codeGen(astContext);
    builder.SetInsertPoint(tempBB);
    return nullptr;
}

ConstPart::ConstPart(ConstExprList *cel) : cel(cel) {}

llvm::Value *ConstPart::codeGen(ASTContext &astContext) {
    return cel->codeGen(astContext);
}

ConstExprList::ConstExprList() = default;

void ConstExprList::pushBack(ConstValueDecl *ce) {
    vec.push_back(ce);
}

llvm::Value *ConstExprList::codeGen(ASTContext &astContext) {
    for (auto &i : vec) {
        llvm::Type *type = astContext.getType(i->value->typeName);
        if (type == nullptr) return nullptr;
        llvm::Constant *initial = getInitial(type);
        llvm::Value *var = new llvm::GlobalVariable(module, type, false, llvm::GlobalValue::ExternalLinkage, initial, i->name);
        astContext.addVar(i->name, var);
        astContext.addConst(i->name);
        llvm::Value *v = i->value->codeGen(astContext);
        v = ASTUtilitiy::createCast(v, type);
        if (v == nullptr) return nullptr;
        builder.CreateStore(v, var);
    }
    return nullptr;
}

ConstValueDecl::ConstValueDecl(std::string name, ConstValue *value) : name(std::move(name)), value(value) {}

llvm::Value *ConstValueDecl::codeGen(ASTContext &astContext) {
    return nullptr;
}

ConstIntValue::ConstIntValue(const std::string &val) : val(stoi(val)) { typeName = "int"; }

ConstValue *ConstIntValue::setNeg() {
    val = -val;
    return this;
}

llvm::Value *ConstIntValue::codeGen(ASTContext &astContext) {
    return builder.getInt64(dynamic_cast<ConstIntValue *>(this)->val);
}

ConstRealValue::ConstRealValue(const std::string &val) : val(stof(val)) { typeName = "real"; }

ConstValue *ConstRealValue::setNeg() {
    val = -val;
    return this;
}

llvm::Value *ConstRealValue::codeGen(ASTContext &astContext) {
    return llvm::ConstantFP::get(builder.getDoubleTy(), dynamic_cast<ConstRealValue *>(this)->val);
}

ConstCharValue::ConstCharValue(const std::string &val) : val(val[1]) { typeName = "char"; }

ConstValue *ConstCharValue::setNeg() {
    return this;
}

llvm::Value *ConstCharValue::codeGen(ASTContext &astContext) {
    return builder.getInt8(dynamic_cast<ConstCharValue *>(this)->val);
}

TypeDeclList::TypeDeclList() = default;

void TypeDeclList::pushBack(TypeDefinition *td) {
    vec.push_back(td);
}

SysCallProcStmt::SysCallProcStmt(const std::string &nm, ExpressionList *el) : nm(nm), el(el) {}

llvm::Value *TypeDeclList::codeGen(ASTContext &astContext) {
    for (auto &i : vec) {
        i->codeGen(astContext);
    }
    return TypePart::codeGen(astContext);
}

SysType::SysType(const std::string &decltp) : SimpleType(decltp) {}

CustomType::CustomType(std::string nm, const std::string &decltp) : SimpleType(decltp), nm(std::move(nm)) {}

llvm::Value *CustomType::codeGen(ASTContext &astContext) {
    // TODO
    return nullptr;
}

EnumType::EnumType(NameList *nl, const std::string &decltp) : SimpleType(decltp), nl(nl) {}

llvm::Value *EnumType::codeGen(ASTContext &astContext) {
    // TODO
    return nullptr;
}

RangeType::RangeType(ConstValue *l, ConstValue *r, const std::string &decltp) : SimpleType(decltp), l(l), r(r) {}

llvm::Value *RangeType::codeGen(ASTContext &astContext) {
    // TODO
    return nullptr;
}

ArrayType::ArrayType(SimpleType *st, TypeDecl *td) : st(st), td(td) {}

llvm::Value *ArrayType::codeGen(ASTContext &astContext) {
    // TODO
    return nullptr;
}

llvm::Value *SysType::codeGen(ASTContext &astContext) {
    // keeps empty
    return nullptr;
}

llvm::Value *ParaDeclList::codeGen(ASTContext &astContext) {
    // keeps empty
    return nullptr;
}

RecordType::RecordType(FieldDeclList *fdl) : fdl(fdl) {}

llvm::Value *RecordType::codeGen(ASTContext &astContext) {
    return fdl->codeGen(astContext);
}

FieldDeclList::FieldDeclList() = default;

void FieldDeclList::pushBack(FieldDecl *fd) {
    vec.push_back(fd);
}

llvm::Value *FieldDeclList::codeGen(ASTContext &astContext) {
    // TODO
    return nullptr;
}

FieldDecl::FieldDecl(NameList *nl, TypeDecl *td) : nl(nl), td(td) {}

llvm::Value *FieldDecl::codeGen(ASTContext &astContext) {
    // TODO
    return nullptr;
}

void NameList::pushBack(const std::string &nm) {
    vec.push_back(nm);
}

NameList::NameList() = default;

llvm::Value *ParaTypeList::codeGen(ASTContext &astContext) {
    return nullptr;
}

llvm::Value *NameList::codeGen(ASTContext &astContext) {
    // keeps empty
    return nullptr;
}

void VarDeclList::pushBack(VarDecl *vd) {
    vec.push_back(vd);
}

llvm::Value *VarDeclList::codeGen(ASTContext &astContext) {
    for (auto &i : vec) {
        i->codeGen(astContext);
    }
    return nullptr;
}

VarDecl::VarDecl(NameList *nl, TypeDecl *td) : nl(nl), td(td) {}

llvm::Value *VarDecl::codeGen(ASTContext &astContext) {
    llvm::Type *type = astContext.getType(td->declTp);
    if (type == nullptr) {
        return nullptr;
    }
    std::vector<std::string> &nv = nl->vec;
    for (auto &i : nv) {
        llvm::Constant *initial = getInitial(type);
        llvm::Value *var(nullptr);
        if(astContext.currentFunction->llvmFunction == startFunc)
            var = new llvm::GlobalVariable(module, type, false, llvm::GlobalVariable::ExternalLinkage, getInitial(type));
        else
            var = builder.CreateAlloca(type, nullptr, i);
        astContext.addVar(i, var);
    }
    return nullptr;
}

RoutinePart::RoutinePart() = default;

void RoutinePart::pushBack(RoutineDecl *rd) {
    vec.push_back(rd);
}

llvm::Value *RoutinePart::codeGen(ASTContext &astContext) {
    for (auto r : vec)
        r->codeGen(astContext);
    return nullptr;
}

Function::Function(FunctionHead *fh, Routine *rt) : fh(fh), RoutineDecl(rt) {}

ParaDeclList::ParaDeclList() = default;

void ParaDeclList::pushBack(ParaTypeList *ptl) {
    vec.push_back(ptl);
}

ParaTypeList::ParaTypeList(VarParaList *vpl, SimpleType *st) : vpl(vpl), st(st) {}

void StmtList::pushBack(Stmt *st) {
    vec.push_back(st);
}

StmtList::StmtList() = default;

llvm::Value *StmtList::codeGen(ASTContext &astContext) {
    for (auto stmt : vec)
        stmt->codeGen(astContext);
    return nullptr;
}

Stmt::Stmt() : label(0), hasLabel(false) {}

llvm::Value *Stmt::codeGen(ASTContext &astContext) {
    // TODO: label operations
    return nullptr;
}

void Stmt::addLabel(const std::string &str) {
    hasLabel = true;
    label = stoi(str);
}

NameLeftValue::NameLeftValue(std::string nm) : nm(std::move(nm)) {}

IndexLeftValue::IndexLeftValue(std::string nm, Expression *expr) : nm(std::move(nm)), expr(expr) {}

MemberLeftValue::MemberLeftValue(std::string nm1, std::string nm2) : nm1(std::move(nm1)), nm2(std::move(nm2)) {}

NameProcStmt::NameProcStmt(std::string nm) : nm(std::move(nm)) {}

llvm::Value *NameProcStmt::codeGen(ASTContext &astContext) {
    return nullptr;
}

CallProcStmt::CallProcStmt(std::string nm, ArgsList *al) : nm(std::move(nm)), al(al) {}

llvm::Value *CallProcStmt::codeGen(ASTContext &astContext) {
    ASTFunction *myfunc = astContext.getFunction(nm);
    if (myfunc == nullptr) {
        std::cerr << "No Function" << std::endl;
        return nullptr;
    }
    else {
        std::vector<llvm::Type *> &argTypes = myfunc->argTypes;
        std::vector<llvm::Value *> exprListValues;
        exprListValues.reserve(al->vec.size());
        for (auto expr : al->vec)
            exprListValues.push_back(expr->codeGen(astContext));
        if (exprListValues.size() < argTypes.size())
            std::cerr << "Too Few Arguments" << std::endl;
        else if (exprListValues.size() > argTypes.size())
            std::cerr << "Too Many Arguments" << std::endl;

        if (argTypes.empty()) {
            builder.CreateCall(myfunc->llvmFunction);
        }
        else {
            std::vector<llvm::Value *> argValues;
            for (decltype(argTypes.size()) i = 0; i < argTypes.size(); i++) {
                llvm::Value *v = ASTUtilitiy::createCast(exprListValues[i], argTypes[i]);
                if (v == nullptr)
                    std::cerr << "Wrong Type" << std::endl;
                argValues.push_back(v);
            }
            builder.CreateCall(myfunc->llvmFunction, argValues);
        }
        return nullptr;
    }
}

llvm::Value *SysCallProcStmt::codeGen(ASTContext &astContext) {
    ASTFunction *intFunc = astContext.getFunction("intWrite");
    ASTFunction *doubleFunc = astContext.getFunction("doubleWrite");
    ASTFunction *charFunc = astContext.getFunction("charWrite");
    llvm::Value* arg;
    std::vector<llvm::Value*> args;
    for (auto & j : el->vec) {
        arg = j->codeGen(astContext);
        if (arg->getType()->isDoubleTy()) {
            args.clear();
            args.push_back(arg);
            builder.CreateCall(doubleFunc->llvmFunction, args);
        } else if (arg->getType()->isIntegerTy(64)) {
            args.clear();
            args.push_back(arg);
            builder.CreateCall(intFunc->llvmFunction, args);
        } else if (arg->getType()->isIntegerTy(8)) {
            args.clear();
            args.push_back(arg);
            builder.CreateCall(charFunc->llvmFunction, args);
        }
    }
    if(nm == "writeln") {
        ASTFunction *endlFunc = astContext.getFunction("writeLn");
        builder.CreateCall(endlFunc->llvmFunction);
    }
    return nullptr;
}

ReadProcStmt::ReadProcStmt(LeftValue *lv) : lv(lv) {}

llvm::Value *ReadProcStmt::codeGen(ASTContext &astContext) {
    return nullptr;
}

AssignStmt::AssignStmt(LeftValue *lv, Expression *expr) : lv(lv), expr(expr) {}

ElseClause::ElseClause() : st(nullptr) {}

ElseClause::ElseClause(Stmt *st) : st(st) {}

llvm::Value *ElseClause::codeGen(ASTContext &astContext) {
    return st->codeGen(astContext);
}

IfStmt::IfStmt(Expression *expr, Stmt *st, ElseClause *ec) : expr(expr), st(st), ec(ec) {}

llvm::Value *IfStmt::codeGen(ASTContext &astContext) {
    llvm::Value* CondV = expr->codeGen(astContext);
    if(CondV == nullptr) return nullptr;
    llvm::Function* TF = builder.GetInsertBlock()->getParent();
    llvm::BasicBlock* thenBB = llvm::BasicBlock::Create(context, "then", TF);
    llvm::BasicBlock* elseBB = nullptr;
    if(ec->st) elseBB = llvm::BasicBlock::Create(context, "else");
    llvm::BasicBlock* mergeBB = llvm::BasicBlock::Create(context, "merge");
    if(ec->st == nullptr)
        builder.CreateCondBr(CondV, thenBB, mergeBB);
    else
        builder.CreateCondBr(CondV, thenBB, elseBB);
    builder.SetInsertPoint(thenBB);
    st->codeGen(astContext);
    builder.CreateBr(mergeBB);
    thenBB = builder.GetInsertBlock();

    if(ec->st) {
        TF->getBasicBlockList().push_back(elseBB);
        builder.SetInsertPoint(elseBB);
        ec->codeGen(astContext);
        builder.CreateBr(mergeBB);
        elseBB = builder.GetInsertBlock();
    }

    TF->getBasicBlockList().push_back(mergeBB);
    builder.SetInsertPoint(mergeBB);
    return nullptr;
}

WhileStmt::WhileStmt(Expression *expr, Stmt *st) : expr(expr), st(st) {}

llvm::Value *WhileStmt::codeGen(ASTContext &astContext) {
    llvm::Function* TF = builder.GetInsertBlock()->getParent();
    llvm::BasicBlock* preBB = builder.GetInsertBlock();
    llvm::BasicBlock* loopBB = llvm::BasicBlock::Create(context, "loop", TF);
    builder.CreateBr(loopBB);

    builder.SetInsertPoint(loopBB);
    llvm::Value* condV = expr->codeGen(astContext);
    if(condV == nullptr) return nullptr;

    llvm::BasicBlock* execBB = llvm::BasicBlock::Create(context, "exec");
    llvm::BasicBlock* afterBB = llvm::BasicBlock::Create(context, "after");

    builder.CreateCondBr(condV, execBB, afterBB);
    TF->getBasicBlockList().push_back(execBB);
    TF->getBasicBlockList().push_back(afterBB);
    builder.SetInsertPoint(execBB);
    st->codeGen(astContext);
    builder.CreateBr(loopBB);
    builder.SetInsertPoint(afterBB);
    return nullptr;
}

Direction::Direction(std::string dir) : dir(std::move(dir)) {}

llvm::Value *Direction::codeGen(ASTContext &astContext) {
    // keeps empty
    return nullptr;
}

CaseStmt::CaseStmt(Expression *expr, CaseExprList *cel) : expr(expr), cel(cel) {}

llvm::Value *CaseStmt::codeGen(ASTContext &astContext) {
    llvm::Function* TF = builder.GetInsertBlock()->getParent();
    llvm::BasicBlock* sw = llvm::BasicBlock::Create(context, "switch", TF);
    llvm::BasicBlock* after = llvm::BasicBlock::Create(context, "after");
    builder.CreateBr(sw);
    builder.SetInsertPoint(sw);
    llvm::Value* cur = expr->codeGen(astContext);
    llvm::Type* type = cur->getType();
    if(cur == nullptr) {
        std::cerr << "unable to get value of expr" << std::endl;
        return nullptr;
    }
    std::vector<llvm::BasicBlock*> js;
    std::vector<llvm::BasicBlock*> cs;
    for(auto & i : cel->vec){
        llvm::BasicBlock* c = llvm::BasicBlock::Create(context, "case");
        llvm::BasicBlock* j = llvm::BasicBlock::Create(context, "jump");
        llvm::Value* temp = i->codeGen(astContext);
        llvm::Value* condV;
        if(type->isDoubleTy()){
            condV = ASTUtilitiy::createCast(temp, type);
            condV = builder.CreateFCmpOEQ(cur, temp);
        }else{
            condV = ASTUtilitiy::createCast(cur, temp->getType());
            condV = builder.CreateICmpEQ(cur, temp);
        }
        builder.CreateCondBr(condV, j, c);
        builder.SetInsertPoint(j);
        i->codeGen2(astContext);
        builder.CreateBr(after);
        cs.push_back(c);
        js.push_back(j);
        builder.SetInsertPoint(c);
    }
    builder.CreateBr(after);
    for(auto & c : cs) TF->getBasicBlockList().push_back(c);
    for(auto & j : js) TF->getBasicBlockList().push_back(j);
    builder.SetInsertPoint(sw);
    builder.SetInsertPoint(after);
    TF->getBasicBlockList().push_back(after);
    return nullptr;
}

void CaseExprList::pushBack(CaseExpr *ce) {
    vec.push_back(ce);
}

llvm::Value *CaseExprList::codeGen(ASTContext &astContext) {
    return nullptr;
}

CaseExprList::CaseExprList() = default;

CaseExpr::CaseExpr(Stmt *st) : st(st) {}

llvm::Value *CaseExpr::codeGen2(ASTContext &astContext) {
    return st->codeGen(astContext);
}

ConstValueCaseExpr::ConstValueCaseExpr(ConstValue *cv, Stmt *st) : CaseExpr(st), cv(cv) {}

llvm::Value *ConstValueCaseExpr::codeGen(ASTContext &astContext) {
    return cv->codeGen(astContext);
}

NameCaseExpr::NameCaseExpr(std::string nm, Stmt *st) : CaseExpr(st), nm(std::move(nm)) {}

llvm::Value *NameCaseExpr::codeGen(ASTContext &astContext) {
    return builder.CreateLoad(astContext.getVar(nm));
}

GotoStmt::GotoStmt(const std::string &str) : label(stoi(str)) {}

llvm::Value *GotoStmt::codeGen(ASTContext &astContext) {
    return Stmt::codeGen(astContext);
}

void ExpressionList::pushBack(Expression *expr) {
    vec.push_back(expr);
}

ExpressionList::ExpressionList() { vec.clear(); }

BinaryExpr::BinaryExpr(Expression *l, Expression *r, std::string op) : l(l), r(r), op(std::move(op)) {}

CalcExpr::CalcExpr(Expression *l, Expression *r, std::string op) : l(l), r(r), op(std::move(op)) {}

NameFactor::NameFactor(std::string nm) : nm(std::move(nm)) {}

CallFactor::CallFactor(std::string nm, ArgsList *al) : nm(std::move(nm)), al(al) {}

llvm::Value *SysFuncFactor::codeGen(ASTContext &astContext) {
    // TODO
    return nullptr;
}

ConstFactor::ConstFactor(ConstValue *cv) : cv(cv) {}

llvm::Value *ConstFactor::codeGen(ASTContext &astContext) {
    llvm::Value* v = cv->codeGen(astContext);
    if(noT) builder.CreateNot(v);
    if(neg) builder.CreateNeg(v);
    return v;
}

ParenthesesFactor::ParenthesesFactor(Expression *expr) : expr(expr) {}

llvm::Value *ParenthesesFactor::codeGen(ASTContext &astContext) {
    return expr->codeGen(astContext);
}

IndexFactor::IndexFactor(std::string nm, Expression *expr) : nm(std::move(nm)), expr(expr) {}

llvm::Value *IndexFactor::codeGen(ASTContext &astContext) {
    // TODO
    return nullptr;
}

MemberFactor::MemberFactor(std::string nm1, std::string nm2) : nm1(std::move(nm1)), nm2(std::move(nm2)) {}

llvm::Value *MemberFactor::codeGen(ASTContext &astContext) {
    // TODO
    return nullptr;
}

Factor *Factor::setNot() {
    noT = !noT;
    return this;
}

Factor *Factor::setNeg() {
    neg = !neg;
    return this;
}

void ArgsList::pushBack(Expression *expr) {
    vec.push_back(expr);
}

llvm::Value *ArgsList::codeGen(ASTContext &astContext) {
    // keeps empty
    return nullptr;
}

ArgsList::ArgsList() = default;

RoutineDecl::RoutineDecl(Routine *rt) : rt(rt) {}

Procedure::Procedure(ProcedureHead *ph, Routine *rt) : RoutineDecl(rt), ph(ph) {}

llvm::Value *Procedure::codeGen(ASTContext &astContext) {
    ASTContext newContext(&astContext);
    ph->codeGen(newContext);
    rt->codeGen(newContext);
    builder.CreateRetVoid();
    llvm::verifyFunction(*(newContext.currentFunction->llvmFunction));
    return nullptr;
}


//Function Declaration
llvm::Value *Function::codeGen(ASTContext &astContext) {
    ASTContext newContext(&astContext);
    fh->codeGen(newContext);
    rt->codeGen(newContext);
    builder.CreateRet(builder.CreateLoad(newContext.getVar(fh->nm)));
    llvm::verifyFunction(*(newContext.currentFunction->llvmFunction));
    return nullptr;
}

llvm::Value *FunctionHead::codeGen(ASTContext &astContext) {
    // Generate Function instance
    std::vector<llvm::Type *> argType;
    for (const auto &i : dynamic_cast<ParaDeclList *>(para)->vec) {
        for (const auto &j : dynamic_cast<NameList *>(i->vpl)->vec) {
            argType.push_back(astContext.getType(i->st->declTp));
        }
    }
    llvm::ArrayRef<llvm::Type *> argTypeArrayRef(argType);
    llvm::FunctionType *funcType = llvm::FunctionType::get(astContext.getType(st->declTp), argTypeArrayRef, false);
    llvm::Function *llvmFunc = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, nm + "_sp", module);
    //                                                         use &module in old version of llvm                   ^~~~~~~
    auto *func = new ASTFunction(nm, llvmFunc, astContext.getType(st->declTp), argType);
    astContext.parent->addFunction(nm, func);
    astContext.currentFunction = func;

    // Start Block
    ASTUtilitiy::startBlock(astContext);
    // Generate return var
    llvm::Value *var = builder.CreateAlloca(astContext.getType((st->declTp)), nullptr, nm);
    astContext.addVar(func->name, var);
    // Generate para var
    auto argI = llvmFunc->arg_begin();
    for (const auto &i : dynamic_cast<ParaDeclList *>(para)->vec) {
        for (const auto &j : dynamic_cast<NameList *>(i->vpl)->vec) {
            llvm::Value *par = builder.CreateAlloca(astContext.getType(i->st->declTp), nullptr, j);
            builder.CreateStore(argI++, par);
            astContext.addVar(j, par);
        }
    }
    return nullptr;
}

//Assign
llvm::Value *AssignStmt::codeGen(ASTContext &astContext) {
    llvm::Value *var = lv->codeGen(astContext);
    if (var == nullptr)
        std::cerr << "No such Value of function is not implemented" << std::endl;
    else {
        llvm::Value *value = expr->codeGen(astContext);
        auto *pt = static_cast<llvm::PointerType *>(var->getType());
        value = ASTUtilitiy::createCast(value, pt->getElementType());
        if (value == nullptr)
            std::cerr << "Wrong Type Assignment" << std::endl;
        builder.CreateStore(value, var);
    }
    return nullptr;
}

llvm::Value *NameLeftValue::codeGen(ASTContext &astContext) {
    llvm::Value *var = astContext.getVar(nm);
    if (var == nullptr) std::cerr << "variable not declared" << std::endl;
    if (astContext.checkConst(nm)) {
        std::cerr << "variable is const" << std::endl;
    }
    return var;
}

llvm::Value *IndexLeftValue::codeGen(ASTContext &astContext) {
    // TODO
    return nullptr;
}

llvm::Value *MemberLeftValue::codeGen(ASTContext &astContext) {
    // TODO
    return nullptr;
}

llvm::Value *ExpressionList::codeGen(ASTContext &astContext) {
    llvm::Value *last;
    for (auto i = vec.size() - 1; i >= 0; --i) {
        last = vec[i]->codeGen(astContext);
    }
    return last;
}

llvm::Value *BinaryExpr::codeGen(ASTContext &astContext) {
    llvm::Value *lv = l->codeGen(astContext);
    llvm::Value *rv = r->codeGen(astContext);
    if (op == "or") {
        return builder.CreateOr(lv, rv);
    } else {
        return builder.CreateAnd(lv, rv);
    }
    return nullptr;
}

llvm::Value *CalcExpr::codeGen(ASTContext &astContext) {
    llvm::Value *lv = l->codeGen(astContext);
    llvm::Value *rv = r->codeGen(astContext);
    if ((lv->getType()->isDoubleTy() || lv->getType()->isIntegerTy(64)) //only when both are int or double
        && (rv->getType()->isDoubleTy() || rv->getType()->isIntegerTy(64))) {
        if (lv->getType()->isDoubleTy()) {
            rv = ASTUtilitiy::createCast(rv, lv->getType());
        } else {
            lv = ASTUtilitiy::createCast(lv, rv->getType());
        }
        if (lv->getType()->isDoubleTy()) { // as double
            if (op == ">=") { return builder.CreateFCmpOGE(lv, rv); }
            else if (op == ">") { return builder.CreateFCmpOGT(lv, rv); }
            else if (op == "<=") { return builder.CreateFCmpOLE(lv, rv); }
            else if (op == "<") { return builder.CreateFCmpOLT(lv, rv); }
            else if (op == "=") { return builder.CreateFCmpOEQ(lv, rv); }
            else if (op == "<>") { return builder.CreateFCmpONE(lv, rv); }
            else if (op == "+") { return builder.CreateFAdd(lv, rv); }
            else if (op == "-") { return builder.CreateFSub(lv, rv); }
            else if (op == "*") { return builder.CreateFMul(lv, rv); }
            else if (op == "/") { return builder.CreateFDiv(lv, rv); }
            else if (op == "mod") { std::cerr << "Wrong llvm::Type" << std::endl; }
        } else { // as int
            if (op == ">=") { return builder.CreateICmpSGE(lv, rv); }
            else if (op == ">") { return builder.CreateICmpSGT(lv, rv); }
            else if (op == "<=") { return builder.CreateICmpSLE(lv, rv); }
            else if (op == "<") { return builder.CreateICmpSLT(lv, rv); }
            else if (op == "=") { return builder.CreateICmpEQ(lv, rv); }
            else if (op == "<>") { return builder.CreateICmpNE(lv, rv); }
            else if (op == "+") { return builder.CreateAdd(lv, rv); }
            else if (op == "-") { return builder.CreateSub(lv, rv); }
            else if (op == "*") { return builder.CreateMul(lv, rv); }
            else if (op == "/") { return builder.CreateSDiv(lv, rv); }
            else if (op == "mod") { return builder.CreateSRem(lv, rv); }
        }
    } else {
        std::cerr << "Wrong llvm::Type" << std::endl;
    }
    return nullptr;
}

llvm::Value *NameFactor::codeGen(ASTContext &astContext) {
    llvm::Value* var = astContext.getVar(nm);

    if (var == nullptr) std::cerr << "variable not declared" << std::endl;

    llvm::Value* v = builder.CreateLoad(var);
    if(noT) builder.CreateNot(v);
    if(neg) builder.CreateNeg(v);
    return v;
}

llvm::Value *CallFactor::codeGen(ASTContext &astContext) {
    ASTFunction *myfunc = astContext.getFunction(nm);
    if (myfunc == nullptr) {
        std::cerr << "No Function" << std::endl;
        return nullptr;
    } else {
        std::vector<llvm::Type *> &argTypes = myfunc->argTypes;
        std::vector<llvm::Value *> exprListValues;
        std::vector<Expression *> &exprList = al->vec;
        exprListValues.reserve(exprList.size());
        for (auto expr : exprList) {
            exprListValues.push_back(expr->codeGen(astContext));
        }
        if (exprListValues.size() < argTypes.size())
            std::cerr << "Too Few Arguments" << std::endl;
        else if (exprListValues.size() > argTypes.size())
            std::cerr << "Too Many Arguments" << std::endl;

        llvm::Value *callResult = nullptr;
        if (argTypes.empty()) {
            callResult = builder.CreateCall(myfunc->llvmFunction);
        } else {
            std::vector<llvm::Value *> argValues;
            for (decltype(argTypes.size()) i = 0; i < argTypes.size(); i++) {
                llvm::Value *v = ASTUtilitiy::createCast(exprListValues[i], argTypes[i]);
                if (v == nullptr) {
                    std::cerr << "Wrong Type" << std::endl;
                }
                argValues.push_back(v);
            }
            callResult = builder.CreateCall(myfunc->llvmFunction, argValues);
        }

        return callResult;
    }
}

SysFuncCallFactor::SysFuncCallFactor(std::string nm, ArgsList *al) : nm(std::move(nm)), al(al) {}

SysFuncFactor::SysFuncFactor(const std::string &nm) : nm(nm) {}

llvm::Value *SysFuncCallFactor::codeGen(ASTContext &astContext) {
    // TODO
    return nullptr;
}

llvm::Type *ASTContext::getType(const std::string &name) {
    llvm::Type *type = typeTable[name];
    if (type == nullptr && parent != nullptr) {
        type = parent->getType(name);
    }
    if (type == nullptr) {
        if (name == "void") {
            //errorMsg = "variable has incomplete type 'void'";
            std::cerr << "variable has incomplete type 'void'" << std::endl;
        } else {
            //errorMsg = "undeclared type '"+name+"'";
            std::cerr << "undeclared type '" << name << "'" << std::endl;
        }
    }
    return type;
}

ASTFunction *ASTContext::getFunction(const std::string &name) {
    ASTFunction *function = functionTable[name];
    if (function == nullptr && parent != nullptr) {
        return parent->getFunction(name);
    }
    if (function == nullptr) {
        //errorMsg = "undeclared function '"+name+"'";
        std::cerr << "undeclared function '" << name << "'" << std::endl;
    }
    return function;
}

llvm::Value *ASTContext::getVar(const std::string &name) {
    llvm::Value *var = varTable[name];
    if (var == nullptr && parent != nullptr) {
        return parent->getVar(name);
    }
    if (var == nullptr) {
        //errorMsg = "undeclared identifier '"+name+"'";
        std::cerr << "undeclared identifier '" << name << "'" << std::endl;
    }
    return var;
}

bool ASTContext::addFunction(const std::string &name, ASTFunction *function) {
    if (functionTable[name]) {
        //errorMsg = "redefine function named '"+name+"'";
        std::cerr << "redefine type named '" << name << "'" << std::endl;
        return false;
    }
    functionTable[name] = function;
    return true;
}

bool ASTContext::addVar(const std::string &name, llvm::Value *value) {
    if (varTable[name]) {
        //errorMsg = "redefine variable named '"+name+"'";
        std::cerr << "redefine type named '" << name << "'" << std::endl;
        return false;
    }
    varTable[name] = value;
    return true;
}

bool ASTContext::addType(const std::string &name, llvm::Type *type) {
    if (typeTable[name]) {
        //errorMsg =  "redefine type named '"+name+"'";
        std::cerr << "redefine type named '" << name << "'" << std::endl;
        return false;
    }
    typeTable[name] = type;
    return true;
}

ASTContext::ASTContext(ASTContext *p) : parent(p) {
    if (p != nullptr) currentFunction = parent->currentFunction;
    else currentFunction = nullptr;
    addType("int", builder.getInt64Ty());
    addType("char", builder.getInt8Ty());
    addType("real", builder.getDoubleTy());
    addType("bool", builder.getInt1Ty());
}

void ASTContext::addConst(const std::string &name) {
    constTable.insert(name);
}

bool ASTContext::checkConst(const std::string &name) const {
    if(constTable.count(name)) return true;
    if(parent) return parent->checkConst(name);
    return false;
}

ASTFunction::ASTFunction(std::string name, llvm::Function *llvmFunction, llvm::Type *returnType,
                         std::vector<llvm::Type *> &argTypes)
        : name(std::move(name)), llvmFunction(llvmFunction), returnType(returnType), argTypes(argTypes),
          returnVal(nullptr) {
    returnType = llvmFunction->getReturnType();
}

TypeDefinition::TypeDefinition(std::string nm, TypeDecl *td) : nm(std::move(nm)), td(td) {}

llvm::Value *TypeDefinition::codeGen(ASTContext &astContext) {
    // TODO
    return nullptr;
}

NamedRangeType::NamedRangeType(std::string cv1, std::string cv2, const std::string &decltp) : SimpleType(decltp),
                                                                                              cv1(std::move(cv1)),
                                                                                              cv2(std::move(cv2)) {}

llvm::Value *NamedRangeType::codeGen(ASTContext &astContext) {
    // TODO
    return nullptr;
}

FunctionHead::FunctionHead(std::string nm, Parameters *para, SimpleType *st) : nm(std::move(nm)), para(para), st(st) {}

ProcedureHead::ProcedureHead(std::string nm, Parameters *para) : nm(std::move(nm)), para(para) {}

llvm::Value *ProcedureHead::codeGen(ASTContext &astContext) {
    // Generate Function instance
    std::vector<llvm::Type *> argType;
    for (const auto &i : dynamic_cast<ParaDeclList *>(para)->vec) {
        for (const auto &j : dynamic_cast<NameList *>(i->vpl)->vec) {
            argType.push_back(astContext.getType(i->st->declTp));
        }
    }
    llvm::ArrayRef<llvm::Type *> argTypeArrayRef(argType);
    llvm::FunctionType *funcType = llvm::FunctionType::get(builder.getVoidTy(), argTypeArrayRef, false);
    llvm::Function *llvmFunc = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, nm + "_sp", module);
    auto *func = new ASTFunction(nm, llvmFunc, builder.getVoidTy(), argType);
    astContext.parent->addFunction(nm, func);
    astContext.currentFunction = func;

    // Start Block
    ASTUtilitiy::startBlock(astContext);
    // Generate para var
    auto argI = llvmFunc->arg_begin();
    for (const auto &i : dynamic_cast<ParaDeclList *>(para)->vec) {
        for (const auto &j : dynamic_cast<NameList *>(i->vpl)->vec) {
            llvm::Value *var = builder.CreateAlloca(astContext.getType(i->st->declTp), nullptr, j);
            builder.CreateStore(argI++, var);
            astContext.addVar(j, var);
        }
    }
    return nullptr;
}

RepeatStmt::RepeatStmt(StmtList *sl, Expression *expr) : sl(sl), expr(expr) {}

llvm::Value *RepeatStmt::codeGen(ASTContext &astContext) {
    llvm::Function* TF = builder.GetInsertBlock()->getParent();
    llvm::BasicBlock* loopBB = llvm::BasicBlock::Create(context, "loop", TF);

    builder.CreateBr(loopBB);
    builder.SetInsertPoint(loopBB);

    sl->codeGen(astContext);

    llvm::Value* condV = expr->codeGen(astContext);
    if(condV == nullptr) return nullptr;

    llvm::BasicBlock* afterBB = llvm::BasicBlock::Create(context, "after");

    builder.CreateCondBr(condV, afterBB, loopBB);
    TF->getBasicBlockList().push_back(afterBB);
    builder.SetInsertPoint(afterBB);
    return nullptr;
}

llvm::Value *ForStmt::codeGen(ASTContext &astContext) {
    llvm::Value* var = astContext.getVar(nm);
    if(var == nullptr) return nullptr;

    llvm::Value* initVal = expr->codeGen(astContext);
    builder.CreateStore(initVal, var); // i = 1;

    llvm::Function* TF = builder.GetInsertBlock()->getParent();
    llvm::BasicBlock* preBB = builder.GetInsertBlock();
    llvm::BasicBlock* loopheadBB = llvm::BasicBlock::Create(context, "loop_head", TF);
    llvm::BasicBlock* loopBB = llvm::BasicBlock::Create(context, "loop", TF);

    llvm::Value *condV = nullptr;
    llvm::Value *bound = toExpr->codeGen(astContext); // bound = toExpr

    builder.CreateBr(loopheadBB);       // jmp loop
    builder.SetInsertPoint(loopheadBB); // loop:

    if(dir->dir == "to")
        condV = builder.CreateICmpSLE(builder.CreateLoad(var), bound, "loop_cond");
    else if(dir->dir == "downto")
        condV = builder.CreateICmpSGE(builder.CreateLoad(var), bound, "loop_cond");

    llvm::BasicBlock* afterBB = llvm::BasicBlock::Create(context, "after_loop", TF);
    builder.CreateCondBr(condV, loopBB, afterBB);
    builder.SetInsertPoint(loopBB);

    st->codeGen(astContext); // begin ... end;

    llvm::Value* stepVal = builder.getInt64(1); // it_step = 1
    llvm::Value* nextVal = nullptr;
    if(dir->dir == "to")
        nextVal = builder.CreateAdd(builder.CreateLoad(var), stepVal, "next_iter"); // temp = i+1
    else if(dir->dir == "downto")
        nextVal = builder.CreateSub(builder.CreateLoad(var), stepVal, "next_iter"); // temp = i-1
    builder.CreateStore(nextVal, var); // i = temp;
    builder.CreateBr(loopheadBB);

    builder.SetInsertPoint(afterBB);
    return llvm::Constant::getNullValue(builder.getInt64Ty());
}

ForStmt::ForStmt(std::string nm, Expression *expr, Direction *dir, Expression *toExpr, Stmt *st) : nm(std::move(nm)),
                                                                                                          expr(expr),
                                                                                                          dir(dir),
                                                                                                          toExpr(toExpr),
                                                                                                          st(st) {}

llvm::Value *LabelPart::codeGen(ASTContext &astContext) {
    // keeps empty
    return nullptr;
}

llvm::Value *TypePart::codeGen(ASTContext &astContext) {
    // TODO
    return nullptr;
}

TypeDecl::TypeDecl(std::string decltp) : declTp(std::move(decltp)) {}

TypeDecl::TypeDecl() = default;

SimpleType::SimpleType(const std::string &decltp) : TypeDecl(decltp) {}

VarParaList::VarParaList() : ref(false) {}
