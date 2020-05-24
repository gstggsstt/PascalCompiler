//
// Created by gster on 5/23/20.
//

#include "ASTNode.h"

Program::Program(ProgramHead *ph, Routine *rt) : ph(ph), rt(rt) {}

ProgramHead::ProgramHead(Name *nm) : nm(nm) {}

Routine::Routine(RoutineHead *rh, RoutineBody *rb) : rh(rh), rb(rb) {}

RoutineHead::RoutineHead(LabelPart *lp, ConstPart *cp, TypePart *tp, VarPart *vp, RoutinePart *rp) : lp(lp), cp(cp),
                                                                                                     tp(tp), vp(vp),
                                                                                                     rp(rp) {}

ConstPart::ConstPart(ConstExprList *cel) : cel(cel) {}

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

ExpressionList::ExpressionList() {}

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
