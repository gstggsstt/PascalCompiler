//
// Created by gster on 5/23/20.
//

#ifndef SPL_ASTNODE_H
#define SPL_ASTNODE_H

#include <string>
#include <llvm/IR/Value.h>
#include <llvm/IR/IRBuilder.h>
#include <vector>

#include "NodeTypes.h"

using namespace std;
using namespace llvm;

static llvm::LLVMContext Context;
static llvm::IRBuilder<> Builder(Context);
static std::unique_ptr<llvm::Module> Module;
static std::map<std::string, llvm::Value> NamedValues;

extern LLVMContext &context;
extern IRBuilder<> builder;
extern Module module;
// extern Function *startFunc;
// extern string errorMsg;
// extern Program *program;
extern Value* createCast(Value *value,Type *type);

class ASTFunction {
public:
	string name;
	Function *llvmFunction;
	Type *returnType;
	vector<Type*> argTypes;
	Value returnVal;
	AstFunction(string name,Function *llvmFunction,Type *returnType,vector<Type*> &argTypes)
		:name(name),llvmFunction(llvmFunction),returnType(returnType),argTypes(argTypes){
		returnType = llvmFunction->getReturnType();
	}
}

class ASTContext {
	ASTContext *parent;
	map<tring,Type*> typeTable;
	map<string,ASTFunction*> functionTable;
	map<string,Value*> varTable;

public:
	ASTFunction *currentFunction;

	ASTContext(ASTContext *parent = NULL):parent(parent) {
		if(parent != NULL) {
			currentFunction = parent->currentFunction;
		} else {
			currentFunction = NULL;
		}
	}

	Type* getType(string name);
	AstFunction* getFunction(string name);
	Value* getVar(string name);
	bool addFunction(string name,AstFunction *astFunction);
	bool addVar(string name,Value *var);
	bool addType(string name,Type *type); // Like typeOf("real"),change string to llvm::Type
}//Used to create symbol table and access link,when create a new block by BEGIN END,create an AST context.

class ASTNode {
protected:
public:
    std::string type;

    ASTNode() {  
};

    virtual llvm::Value *codeGen();
};

class ArgsList {
    std::vector<Expression *> vec;
public:
    void pushBack(Expression *expr);

    ArgsList();
    virtual llvm::Value *codeGen();
};

class ConstValue {
public:
    virtual ConstValue *setNeg() = 0;
    virtual llvm::Value *codeGen();
};

class ConstIntValue : public ConstValue {
    int val;
public:
    ConstValue *setNeg() override;

    ConstIntValue(const std::string &val);
    virtual llvm::Value *codeGen();
};

class ConstRealValue : public ConstValue {
    double val;
public:
    ConstValue *setNeg() override;

    ConstRealValue(const std::string &val);
    virtual llvm::Value *codeGen();
};

class ConstCharValue : public ConstValue {
    char val;
public:
    ConstValue *setNeg() override;

    ConstCharValue(const std::string &val);
    virtual llvm::Value *codeGen();
};

class ConstExprList {
    std::vector<ConstValue *> vec;
public:
    void pushBack(ConstValue *ce);

    ConstExprList();
    virtual llvm::Value *codeGen();
};

class ConstPart {
    ConstExprList *cel;
public:
    ConstPart(ConstExprList *cel);
    virtual llvm::Value *codeGen();
};

class Direction {
    std::string dir;
public:
    Direction(const std::string &dir);
    virtual llvm::Value *codeGen();
};

class Expression {
    virtual llvm::Value *codeGen();
};

class Expr : public Expression {
    virtual llvm::Value *codeGen();
};

class Term : public Expr {
    virtual llvm::Value *codeGen();
};

class CalcExpr : public Term {
    Expression *l;
    Expression *r;
    std::string op;
public:
    CalcExpr(Expression *l, Expression *r, const std::string &op);
    virtual llvm::Value *codeGen();
};

class BinaryExpr : public Term {
	Expression *l;
    Expression *r;
    std::string op;
public:
	BinaryExpr(Expression *l, Expression *r, const std::string &op);
    virtual llvm::Value *codeGen();
};

class ExpressionList {
    std::vector<Expression *> vec;
public :
    void pushBack(Expression *expr);

    ExpressionList();
    virtual llvm::Value *codeGen();
};

class Name {
    std::string name;
public:
    const std::string &getName() const;

    Name(const std::string &name);
    virtual llvm::Value *codeGen();
};

class Program : public ASTNode {
    ProgramHead *ph;
    Routine *rt;
public:
    Program(ProgramHead *ph, Routine *rt);
    virtual llvm::Value *codeGen();
};

class ProgramHead {
    Name *nm;
public:
    ProgramHead(Name *nm);
    virtual llvm::Value *codeGen();
};

class Stmt {
    int label;
    bool hasLabel;
public:
    Stmt();

    Stmt(const std::string &str);
    virtual llvm::Value *codeGen();
};

class CaseExpr {
protected:
    Stmt *st;
public:
    CaseExpr(Stmt *st);
    virtual llvm::Value *codeGen();
};

class ConstValueCaseExpr : public CaseExpr {
    ConstValue *cv;
public:
    ConstValueCaseExpr(ConstValue *cv, Stmt *st);
    virtual llvm::Value *codeGen();
};

class NameCaseExpr : public CaseExpr {
    Name *nm;
public:
    NameCaseExpr(Name *nm, Stmt *st);
    virtual llvm::Value *codeGen();
};

class CaseExprList {
    std::vector<CaseExpr *> vec;
public :
    void pushBack(CaseExpr *ce);

    CaseExprList();
    virtual llvm::Value *codeGen();
};

class ElseClause {
    Stmt *st;
public:
    ElseClause(Stmt *st);

    ElseClause();
    virtual llvm::Value *codeGen();
};

class IfStmt {
    Expression *expr;
    Stmt *st;
    ElseClause *ec;
public:
    IfStmt(Expression *expr, Stmt *st, ElseClause *ec);
    virtual llvm::Value *codeGen();
};

class LeftValue {
    virtual llvm::Value *codeGen();
};

class NameLeftValue : public LeftValue {
    Name *nm;
public:
    NameLeftValue(Name *nm);
    virtual llvm::Value *codeGen();
};

class IndexLeftValue : public LeftValue {
    Name *nm;
    Expression *expr;
public:
    IndexLeftValue(Name *nm, Expression *expr);
    virtual llvm::Value *codeGen();
};

class MemberLeftValue : public LeftValue {
    Name *nm1;
    Name *nm2;
public:
    MemberLeftValue(Name *nm1, Name *nm2);
    virtual llvm::Value *codeGen();
};

class RepeatStmt : public Stmt {
    StmtList *sl;
    Stmt *st;
public:
    RepeatStmt(StmtList *sl, Stmt *st);
    virtual llvm::Value *codeGen();
};

class ProcStmt : public Stmt {
    virtual llvm::Value *codeGen();
};

class NameProcStmt : public ProcStmt {
    Name *nm;
public:
    NameProcStmt(Name *nm);
    virtual llvm::Value *codeGen();
};

class CallProcStmt : public ProcStmt {
    Name *nm;
    ArgsList *al;
public:
    CallProcStmt(Name *nm, ArgsList *al);
    virtual llvm::Value *codeGen();
};

class SysProcStmt : public ProcStmt {
    SysProc *sp;
public:
    SysProcStmt(SysProc *sp);
    virtual llvm::Value *codeGen();
};

class SysCallProcStmt : public ProcStmt {
    SysProc *sp;
    ExpressionList *el;
public:
    SysCallProcStmt(SysProc *sp, ExpressionList *el);
    virtual llvm::Value *codeGen();
};

class Factor : public Term {
public:
    virtual Factor *setNot();

    virtual Factor *setNeg();
    virtual llvm::Value *codeGen();
};

class CallFactor : public Factor {
    Name *nm;
    ArgsList *al;
public:
    CallFactor(Name *nm, ArgsList *al);
    virtual llvm::Value *codeGen();
};

class ConstFactor : public Factor {
    ConstValue *cv;
public:
    ConstFactor(ConstValue *cv);
    virtual llvm::Value *codeGen();
};

class IndexFactor : public Factor {
    Name *nm;
    Expression *expr;
public:
    IndexFactor(Name *nm, Expression *expr);
    virtual llvm::Value *codeGen();
};

class MemberFactor : public Factor {
    Name *nm1;
    Name *nm2;
public:
    MemberFactor(Name *nm1, Name *nm2);
    virtual llvm::Value *codeGen();
};

class NameFactor : public Factor {
    Name *nm;
public:
    NameFactor(Name *nm);
    virtual llvm::Value *codeGen();
};

class SysFunc {
    std::string str;
public:
    SysFunc(const std::string &str);
    virtual llvm::Value *codeGen();
};

class SysFuncCallFactor : public Factor {
    SysFunc *sf;
    ArgsList *al;
public:
    SysFuncCallFactor(SysFunc *sf, ArgsList *al);
    virtual llvm::Value *codeGen();
};

class SysFuncFactor : public Factor {
    SysFunc *sf;
public:
    SysFuncFactor(SysFunc *sf);
    virtual llvm::Value *codeGen();
};

class ParenthesesFactor : public Factor {
    Expression *expr;
public:
    ParenthesesFactor(Expression *expr);
    virtual llvm::Value *codeGen();
};

class ReadProcStmt : public ProcStmt {
    Factor *f;
public:
    ReadProcStmt(Factor *f);
    virtual llvm::Value *codeGen();
};

class GotoStmt : public Stmt {
    int label;
public:
    GotoStmt(std::string str);
    virtual llvm::Value *codeGen();
};

class ForStmt : public Stmt {
    Name *nm;
    Expression *expr;
    Direction *dir;
    Stmt *st;
public:
    ForStmt(Name *nm, Expression *expr, Direction *dir, Stmt *st);
    virtual llvm::Value *codeGen();
};

class AssignStmt : public Stmt {
    LeftValue *lv;
    Expression *expr;
public:
    AssignStmt(LeftValue *lv, Expression *expr);
    virtual llvm::Value *codeGen();
};

class CaseStmt : public Stmt {
    Expression *expr;
    CaseExprList *cel;
public:
    CaseStmt(Expression *expr, CaseExprList *cel);
    virtual llvm::Value *codeGen();
};

class WhileStmt : public Stmt {
    Expression *expr;
    Stmt *st;
public:
    WhileStmt(Expression *expr, Stmt *st);
    virtual llvm::Value *codeGen();
};

class Routine {
    RoutineHead *rh;
    RoutineBody *rb;
public:
    Routine(RoutineHead *rh, RoutineBody *rb);
    virtual llvm::Value *codeGen();
};

class RoutineBody {
    virtual llvm::Value *codeGen();
};

class CompoundStmt : public RoutineBody, public Stmt {
    virtual llvm::Value *codeGen();
};

class StmtList : public CompoundStmt {
    std::vector<Stmt *> vec;
public:
    void pushBack(Stmt *st);

    StmtList();
    virtual llvm::Value *codeGen();
};

class LabelPart {
    virtual llvm::Value *codeGen();
};

class TypePart {
    virtual llvm::Value *codeGen();
};

class VarPart {
    virtual llvm::Value *codeGen();
};

class TypeDecl {
    virtual llvm::Value *codeGen();
};

class VarDecl {
    NameList *nl;
    TypeDecl *td;
public:
    VarDecl(NameList *nl, TypeDecl *td);
    virtual llvm::Value *codeGen();
};

class VarDeclList : public VarPart {
    std::vector<VarDecl *> vec;
public:
    void pushBack(VarDecl *vd);
    virtual llvm::Value *codeGen();
};

class RoutineHead {
    LabelPart *lp;
    ConstPart *cp;
    TypePart *tp;
    VarPart *vp;
    RoutinePart *rp;
public:
    RoutineHead(LabelPart *lp, ConstPart *cp, TypePart *tp, VarPart *vp, RoutinePart *rp);
    virtual llvm::Value *codeGen();
};

class RoutineDecl {
protected:
    Routine *rt;
public:
    RoutineDecl(Routine *rt);
    virtual llvm::Value *codeGen();
};

class Parameters {
    virtual llvm::Value *codeGen();
};

class ParaDeclList : public Parameters {
    std::vector<ParaTypeList *> vec;
public:
    void pushBack(ParaTypeList *ptl);

    ParaDeclList();
    virtual llvm::Value *codeGen();
};

class Function : public RoutineDecl {
    FunctionHead *fh;
public:
    Function(FunctionHead *fh, Routine *rt);
    virtual llvm::Value *codeGen();
};

class FunctionHead {
    Name *nm;
    Parameters *para;
public:
    FunctionHead(Name *nm, Parameters *para);
    virtual llvm::Value *codeGen();
};

class Procedure : public RoutineDecl {
public:
    Procedure(ProcedureHead *ph, Routine *rt);

private:
    ProcedureHead *ph;
    virtual llvm::Value *codeGen();
};

class ProcedureHead {
    virtual llvm::Value *codeGen();
};

class RoutinePart {
    std::vector<RoutineDecl *> vec;
public:
    void pushBack(RoutineDecl *rd);

    RoutinePart();
    virtual llvm::Value *codeGen();
};

class SysProc {
    std::string proc;
public:
    SysProc(const std::string &proc);
    virtual llvm::Value *codeGen();
};

class TypeDeclList : public TypePart {
    std::vector<TypeDefinition *> vec;
public:
    void pushBack(TypeDefinition *td);

    TypeDeclList();
    virtual llvm::Value *codeGen();
};

class TypeDefinition {
    Name *nm;
    TypeDecl *td;
    virtual llvm::Value *codeGen();
};

class SimpleType : public TypeDecl {
    virtual llvm::Value *codeGen();
};

class ArrayType : public TypeDecl {
    SimpleType *st;
    TypeDecl *td;
public:
    ArrayType(SimpleType *st, TypeDecl *td);
    virtual llvm::Value *codeGen();
};

class SysType : public SimpleType {
    std::string tp;
public:
    SysType(const std::string &tp);
    virtual llvm::Value *codeGen();
};

class RecordType {
    FieldDeclList *fdl;
public:
    RecordType(FieldDeclList *fdl);
    virtual llvm::Value *codeGen();
};

class FieldDecl {
    NameList *nl;
    TypeDecl *td;
public:
    FieldDecl(NameList *nl, TypeDecl *td);
    virtual llvm::Value *codeGen();
};

class FieldDeclList {
    std::vector<FieldDecl *> vec;
public:
    void pushBack(FieldDecl *fd);

    FieldDeclList();
    virtual llvm::Value *codeGen();
};

class CustomType : public SimpleType {
    Name *nm;
public:
    CustomType(Name *nm);
    virtual llvm::Value *codeGen();
};

class EnumType : public SimpleType {
    NameList *nl;
public:
    EnumType(NameList *nl);
    virtual llvm::Value *codeGen();
};

class RangeType : public SimpleType {
    ConstValue *l;
    ConstValue *r;
public:
    RangeType(ConstValue *l, ConstValue *r);
    virtual llvm::Value *codeGen();
};

class VarParaList {

    virtual llvm::Value *codeGen();
};

class ParaTypeList {
    VarParaList *vpl;
    SimpleType *st;
public:
    ParaTypeList(VarParaList *vpl, SimpleType *st);
    virtual llvm::Value *codeGen();
};

class NameList : ParaTypeList {
    std::vector<Name *> vec;
public :
    void pushBack(Name *nm);
    virtual llvm::Value *codeGen();
};

#endif //SPL_ASTNODE_H
