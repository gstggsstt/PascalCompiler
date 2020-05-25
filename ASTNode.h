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

static llvm::LLVMContext Context;
static llvm::IRBuilder<> Builder(Context);
static std::unique_ptr<llvm::Module> Module;
static std::map<std::string, llvm::Value> NamedValues;

struct ASTNode {

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

    ASTNode() {};

    virtual llvm::Value *codeGen();
};

struct ArgsList {

    std::vector<Expression *> vec;

    void pushBack(Expression *expr);

    ArgsList();

    virtual llvm::Value *codeGen();
};

struct ConstValue {

    virtual ConstValue *setNeg() = 0;

    virtual llvm::Value *codeGen();
};

struct ConstIntValue : public ConstValue {

    int val;

    ConstValue *setNeg() override;

    ConstIntValue(const std::string &val);

    virtual llvm::Value *codeGen();
};

struct ConstRealValue : public ConstValue {

    double val;

    ConstValue *setNeg() override;

    ConstRealValue(const std::string &val);

    virtual llvm::Value *codeGen();
};

struct ConstCharValue : public ConstValue {

    char val;

    ConstValue *setNeg() override;

    ConstCharValue(const std::string &val);

    virtual llvm::Value *codeGen();
};

struct ConstExprList {

    std::vector<ConstValue *> vec;

    void pushBack(ConstValue *ce);

    ConstExprList();

    virtual llvm::Value *codeGen();
};

struct ConstPart {

    ConstExprList *cel;

    ConstPart(ConstExprList *cel);

    virtual llvm::Value *codeGen();
};

struct Direction {

    std::string dir;

    Direction(const std::string &dir);

    virtual llvm::Value *codeGen();
};

struct Expression {

    virtual llvm::Value *codeGen();
};

struct Expr : public Expression {

    virtual llvm::Value *codeGen();
};

struct Term : public Expr {

    virtual llvm::Value *codeGen();
};

struct CalcExpr : public Term {

    Expression *l;
    Expression *r;
    std::string op;

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

struct ExpressionList {
    std::vector<Expression *> vec;

    void pushBack(Expression *expr);

    ExpressionList();

    virtual llvm::Value *codeGen();
};

struct Name {
    std::string name;

    const std::string &getName() const;

    Name(const std::string &name);

    virtual llvm::Value *codeGen();
};

struct Program : public ASTNode {
    ProgramHead *ph;
    Routine *rt;

    Program(ProgramHead *ph, Routine *rt);

    virtual llvm::Value *codeGen();
};

struct ProgramHead {
    Name *nm;

    ProgramHead(Name *nm);

    virtual llvm::Value *codeGen();
};

struct Stmt {
    int label;
    bool hasLabel;

    Stmt();

    Stmt(const std::string &str);

    virtual llvm::Value *codeGen();
};

struct CaseExpr {
protected:
    Stmt *st;

    CaseExpr(Stmt *st);

    virtual llvm::Value *codeGen();
};

struct ConstValueCaseExpr : public CaseExpr {
    ConstValue *cv;

    ConstValueCaseExpr(ConstValue *cv, Stmt *st);

    virtual llvm::Value *codeGen();
};

struct NameCaseExpr : public CaseExpr {
    Name *nm;

    NameCaseExpr(Name *nm, Stmt *st);

    virtual llvm::Value *codeGen();
};

struct CaseExprList {
    std::vector<CaseExpr *> vec;

    void pushBack(CaseExpr *ce);

    CaseExprList();

    virtual llvm::Value *codeGen();
};

struct ElseClause {
    Stmt *st;

    ElseClause(Stmt *st);

    ElseClause();

    virtual llvm::Value *codeGen();
};

struct IfStmt {
    Expression *expr;
    Stmt *st;
    ElseClause *ec;

    IfStmt(Expression *expr, Stmt *st, ElseClause *ec);

    virtual llvm::Value *codeGen();
};

struct LeftValue {
    virtual llvm::Value *codeGen();
};

struct NameLeftValue : public LeftValue {
    Name *nm;

    NameLeftValue(Name *nm);

    virtual llvm::Value *codeGen();
};

struct IndexLeftValue : public LeftValue {
    Name *nm;
    Expression *expr;

    IndexLeftValue(Name *nm, Expression *expr);

    virtual llvm::Value *codeGen();
};

struct MemberLeftValue : public LeftValue {
    Name *nm1;
    Name *nm2;

    MemberLeftValue(Name *nm1, Name *nm2);

    virtual llvm::Value *codeGen();
};

struct RepeatStmt : public Stmt {
    StmtList *sl;
    Stmt *st;

    RepeatStmt(StmtList *sl, Stmt *st);

    virtual llvm::Value *codeGen();
};

struct ProcStmt : public Stmt {
    virtual llvm::Value *codeGen();
};

struct NameProcStmt : public ProcStmt {
    Name *nm;

    NameProcStmt(Name *nm);

    virtual llvm::Value *codeGen();
};

struct CallProcStmt : public ProcStmt {
    Name *nm;
    ArgsList *al;

    CallProcStmt(Name *nm, ArgsList *al);

    virtual llvm::Value *codeGen();
};

struct SysProcStmt : public ProcStmt {
    SysProc *sp;

    SysProcStmt(SysProc *sp);

    virtual llvm::Value *codeGen();
};

struct SysCallProcStmt : public ProcStmt {
    SysProc *sp;
    ExpressionList *el;

    SysCallProcStmt(SysProc *sp, ExpressionList *el);

    virtual llvm::Value *codeGen();
};

struct Factor : public Term {

    virtual Factor *setNot();

    virtual Factor *setNeg();

    virtual llvm::Value *codeGen();
};

struct CallFactor : public Factor {
    Name *nm;
    ArgsList *al;

    CallFactor(Name *nm, ArgsList *al);

    virtual llvm::Value *codeGen();
};

struct ConstFactor : public Factor {
    ConstValue *cv;

    ConstFactor(ConstValue *cv);

    virtual llvm::Value *codeGen();
};

struct IndexFactor : public Factor {
    Name *nm;
    Expression *expr;

    IndexFactor(Name *nm, Expression *expr);

    virtual llvm::Value *codeGen();
};

struct MemberFactor : public Factor {
    Name *nm1;
    Name *nm2;

    MemberFactor(Name *nm1, Name *nm2);

    virtual llvm::Value *codeGen();
};

struct NameFactor : public Factor {
    Name *nm;

    NameFactor(Name *nm);

    virtual llvm::Value *codeGen();
};

struct SysFunc {
    std::string str;

    SysFunc(const std::string &str);

    virtual llvm::Value *codeGen();
};

struct SysFuncCallFactor : public Factor {
    SysFunc *sf;
    ArgsList *al;

    SysFuncCallFactor(SysFunc *sf, ArgsList *al);

    virtual llvm::Value *codeGen();
};

struct SysFuncFactor : public Factor {
    SysFunc *sf;

    SysFuncFactor(SysFunc *sf);

    virtual llvm::Value *codeGen();
};

struct ParenthesesFactor : public Factor {
    Expression *expr;

    ParenthesesFactor(Expression *expr);

    virtual llvm::Value *codeGen();
};

struct ReadProcStmt : public ProcStmt {
    Factor *f;

    ReadProcStmt(Factor *f);

    virtual llvm::Value *codeGen();
};

struct GotoStmt : public Stmt {
    int label;

    GotoStmt(std::string str);

    virtual llvm::Value *codeGen();
};

struct ForStmt : public Stmt {
    Name *nm;
    Expression *expr;
    Direction *dir;
    Stmt *st;

    ForStmt(Name *nm, Expression *expr, Direction *dir, Stmt *st);

    virtual llvm::Value *codeGen();
};

struct AssignStmt : public Stmt {
    LeftValue *lv;
    Expression *expr;

    AssignStmt(LeftValue *lv, Expression *expr);

    virtual llvm::Value *codeGen();
};

struct CaseStmt : public Stmt {
    Expression *expr;
    CaseExprList *cel;

    CaseStmt(Expression *expr, CaseExprList *cel);

    virtual llvm::Value *codeGen();
};

struct WhileStmt : public Stmt {
    Expression *expr;
    Stmt *st;

    WhileStmt(Expression *expr, Stmt *st);

    virtual llvm::Value *codeGen();
};

struct Routine {
    RoutineHead *rh;
    RoutineBody *rb;

    Routine(RoutineHead *rh, RoutineBody *rb);

    virtual llvm::Value *codeGen();
};

struct RoutineBody {
    virtual llvm::Value *codeGen();
};

struct CompoundStmt : public RoutineBody, public Stmt {
    virtual llvm::Value *codeGen();
};

struct StmtList : public CompoundStmt {
    std::vector<Stmt *> vec;

    void pushBack(Stmt *st);

    StmtList();

    virtual llvm::Value *codeGen();
};

struct LabelPart {
    virtual llvm::Value *codeGen();
};

struct TypePart {
    virtual llvm::Value *codeGen();
};

struct VarPart {
    virtual llvm::Value *codeGen();
};

struct TypeDecl {
    virtual llvm::Value *codeGen();
};

struct VarDecl {
    NameList *nl;
    TypeDecl *td;

    VarDecl(NameList *nl, TypeDecl *td);

    virtual llvm::Value *codeGen();
};

struct VarDeclList : public VarPart {
    std::vector<VarDecl *> vec;

    void pushBack(VarDecl *vd);

    virtual llvm::Value *codeGen();
};

struct RoutineHead {
    LabelPart *lp;
    ConstPart *cp;
    TypePart *tp;
    VarPart *vp;
    RoutinePart *rp;

    RoutineHead(LabelPart *lp, ConstPart *cp, TypePart *tp, VarPart *vp, RoutinePart *rp);

    virtual llvm::Value *codeGen();
};

struct RoutineDecl {
protected:
    Routine *rt;

    RoutineDecl(Routine *rt);

    virtual llvm::Value *codeGen();
};

struct Parameters {
    virtual llvm::Value *codeGen();
};

struct ParaDeclList : public Parameters {
    std::vector<ParaTypeList *> vec;

    void pushBack(ParaTypeList *ptl);

    ParaDeclList();

    virtual llvm::Value *codeGen();
};

struct Function : public RoutineDecl {
    FunctionHead *fh;

    Function(FunctionHead *fh, Routine *rt);

    virtual llvm::Value *codeGen();
};

struct FunctionHead {
    Name *nm;
    Parameters *para;

    FunctionHead(Name *nm, Parameters *para);

    virtual llvm::Value *codeGen();
};

struct Procedure : public RoutineDecl {

    Procedure(ProcedureHead *ph, Routine *rt);

private:
    ProcedureHead *ph;

    virtual llvm::Value *codeGen();
};

struct ProcedureHead {
    virtual llvm::Value *codeGen();
};

struct RoutinePart {
    std::vector<RoutineDecl *> vec;

    void pushBack(RoutineDecl *rd);

    RoutinePart();

    virtual llvm::Value *codeGen();
};

struct SysProc {
    std::string proc;

    SysProc(const std::string &proc);

    virtual llvm::Value *codeGen();
};

struct TypeDeclList : public TypePart {
    std::vector<TypeDefinition *> vec;

    void pushBack(TypeDefinition *td);

    TypeDeclList();

    virtual llvm::Value *codeGen();
};

struct TypeDefinition {
    Name *nm;
    TypeDecl *td;

    virtual llvm::Value *codeGen();
};

struct SimpleType : public TypeDecl {
    virtual llvm::Value *codeGen();
};

struct ArrayType : public TypeDecl {
    SimpleType *st;
    TypeDecl *td;

    ArrayType(SimpleType *st, TypeDecl *td);

    virtual llvm::Value *codeGen();
};

struct SysType : public SimpleType {
    std::string tp;

    SysType(const std::string &tp);

    virtual llvm::Value *codeGen();
};

struct RecordType {
    FieldDeclList *fdl;

    RecordType(FieldDeclList *fdl);

    virtual llvm::Value *codeGen();
};

struct FieldDecl {
    NameList *nl;
    TypeDecl *td;

    FieldDecl(NameList *nl, TypeDecl *td);

    virtual llvm::Value *codeGen();
};

struct FieldDeclList {
    std::vector<FieldDecl *> vec;

    void pushBack(FieldDecl *fd);

    FieldDeclList();

    virtual llvm::Value *codeGen();
};

struct CustomType : public SimpleType {
    Name *nm;

    CustomType(Name *nm);

    virtual llvm::Value *codeGen();
};

struct EnumType : public SimpleType {
    NameList *nl;

    EnumType(NameList *nl);

    virtual llvm::Value *codeGen();
};

struct RangeType : public SimpleType {
    ConstValue *l;
    ConstValue *r;

    RangeType(ConstValue *l, ConstValue *r);

    virtual llvm::Value *codeGen();
};

struct VarParaList {
    virtual llvm::Value *codeGen();
};

struct ParaTypeList {
    VarParaList *vpl;
    SimpleType *st;

    ParaTypeList(VarParaList *vpl, SimpleType *st);

    virtual llvm::Value *codeGen();
};

struct NameList : ParaTypeList {
    std::vector<Name *> vec;

    void pushBack(Name *nm);

    virtual llvm::Value *codeGen();
};

#endif //SPL_ASTNODE_H
