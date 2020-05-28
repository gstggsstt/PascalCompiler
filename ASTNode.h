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
using namespace llvm;
using namespace std;

static llvm::LLVMContext context;
static llvm::IRBuilder<> builder(context);
static llvm::Module module("basic_module", context);
<<<<<<< HEAD
static std::string errorMsg;
static llvm::Function *startFunc;

struct ASTNode {

LLVMContext &context;
IRBuilder<> builder;
llvm::Module module;
string errorMsg;
// extern Function *startFunc;
// extern string errorMsg;
// extern Program *program;
Value* createCast(Value *value,Type *type);};
=======

// extern Function *startFunc;
// extern string errorMsg;
// extern Program *program;
>>>>>>> 794118c55f4c7b5621f391f744dd0adef4b85446
llvm::Value* createCast(llvm::Value *value,llvm::Type *type);

struct ASTFunction {
public:
	const std::string &name;
	llvm::Function *llvmFunction;
	llvm::Type *returnType;
	std::vector<llvm::Type*> argTypes;
	llvm::Value *returnVal;
	ASTFunction(const std::string &name,llvm::Function *llvmFunction,llvm::Type *returnType,std::vector<llvm::Type*> &argTypes);
};

struct ASTContext {
	ASTContext *parent;
	std::map<std::string,llvm::Type*> typeTable;
	std::map<std::string,ASTFunction*> functionTable;
	std::map<std::string,llvm::Value*> varTable;

public:
	ASTFunction *currentFunction;

	ASTContext(ASTContext *parent = nullptr):parent(parent) {
		if(parent != nullptr) {
			currentFunction = parent->currentFunction;
		} else {
			currentFunction = nullptr;
		}
	}

	llvm::Type * getType(const std::string &name);
	ASTFunction * getFunction(const std::string &name);
	llvm::Value * getVar(const std::string &name);
	bool addFunction(const std::string &name, ASTFunction *function);
	bool addVar(const std::string &name, llvm::Value *value);
	bool addType(const std::string &name, llvm::Type *type); // Like typeOf("real"),change string to llvm::Type
};//Used to create symbol table and access link,when create a new block by BEGIN END,create an AST context.

struct ASTNode {
protected:
public:
    std::string type;

    ASTNode() = default;

    virtual llvm::Value *codeGen(ASTContext &astContext);
};

struct ArgsList : public ASTNode {

    std::vector<Expression *> vec;

    void pushBack(Expression *expr);

    ArgsList();

    llvm::Value *codeGen(ASTContext &astContext) override;
<<<<<<< HEAD
};

struct ConstValueDecl{
    const std::string name;
    ConstValue& value;

    ConstValueDecl(const std::string name, ConstValue& value);
};

struct ConstValue {
    std::string typeName;

    virtual ConstValue *setNeg() = 0;

    virtual llvm::Value *codeGen(ASTContext& astcontext);
=======
};

struct ConstValue : public ASTNode {

    virtual ConstValue *setNeg() = 0;

    llvm::Value *codeGen(ASTContext &astContext) override;
>>>>>>> 794118c55f4c7b5621f391f744dd0adef4b85446
};

struct ConstIntValue : public ConstValue {

    int val;

    ConstValue *setNeg() override;

    explicit ConstIntValue(const std::string &val);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct ConstRealValue : public ConstValue {

    double val;

    ConstValue *setNeg() override;

    explicit ConstRealValue(const std::string &val);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct ConstCharValue : public ConstValue {

    char val;

    ConstValue *setNeg() override;

    explicit ConstCharValue(const std::string &val);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct ConstExprList : public ASTNode {

    std::vector<ConstValueDecl *> vec;

    void pushBack(ConstValueDecl *ce);

    ConstExprList();

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct ConstPart : public ASTNode {

    ConstExprList *cel;

    explicit ConstPart(ConstExprList *cel);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct Direction : public ASTNode {

    std::string dir;

    explicit Direction(std::string dir);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct Expression  : public ASTNode{

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct Expr : public Expression {

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct Term : public Expr {

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct CalcExpr : public Term {

    Expression *l;
    Expression *r;
    std::string op;

    CalcExpr(Expression *l, Expression *r, std::string op);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct BinaryExpr : public Term {
	Expression *l;
    Expression *r;
    std::string op;
public:
	BinaryExpr(Expression *l, Expression *r, std::string op);
    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct ExpressionList : public ASTNode {
    std::vector<Expression *> vec;

    void pushBack(Expression *expr);

    ExpressionList();

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct Name : public ASTNode {
    std::string name;

    const std::string &getName() const;

    explicit Name(std::string name);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct Program : public ASTNode {
    ProgramHead *ph;
    Routine *rt;

    Program(ProgramHead *ph, Routine *rt);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct ProgramHead : public ASTNode {
    Name *nm;

    explicit ProgramHead(Name *nm);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct Stmt : public ASTNode {
    int label;
    bool hasLabel;

    Stmt();

    explicit Stmt(const std::string &str);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct CaseExpr : public ASTNode {
protected:
    Stmt *st;

    explicit CaseExpr(Stmt *st);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct ConstValueCaseExpr : public CaseExpr {
    ConstValue *cv;

    ConstValueCaseExpr(ConstValue *cv, Stmt *st);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct NameCaseExpr : public CaseExpr {
    Name *nm;

    NameCaseExpr(Name *nm, Stmt *st);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct CaseExprList : public ASTNode {
    std::vector<CaseExpr *> vec;

    void pushBack(CaseExpr *ce);

    CaseExprList();

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct ElseClause : public ASTNode {
    Stmt *st;

    ElseClause(Stmt *st);

    ElseClause();

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct IfStmt : public ASTNode {
    Expression *expr;
    Stmt *st;
    ElseClause *ec;

    IfStmt(Expression *expr, Stmt *st, ElseClause *ec);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct LeftValue : public ASTNode {
    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct NameLeftValue : public LeftValue {
    Name *nm;

    explicit NameLeftValue(Name *nm);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct IndexLeftValue : public LeftValue {
    Name *nm;
    Expression *expr;

    IndexLeftValue(Name *nm, Expression *expr);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct MemberLeftValue : public LeftValue {
    Name *nm1;
    Name *nm2;

    MemberLeftValue(Name *nm1, Name *nm2);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct RepeatStmt : public Stmt {
    StmtList *sl;
    Stmt *st;

    RepeatStmt(StmtList *sl, Stmt *st);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct ProcStmt : public Stmt {
    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct NameProcStmt : public ProcStmt {
    Name *nm;

    explicit NameProcStmt(Name *nm);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct CallProcStmt : public ProcStmt {
    Name *nm;
    ArgsList *al;

    CallProcStmt(Name *nm, ArgsList *al);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct SysProcStmt : public ProcStmt {
    SysProc *sp;

    explicit SysProcStmt(SysProc *sp);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct SysCallProcStmt : public ProcStmt {
    SysProc *sp;
    ExpressionList *el;

    SysCallProcStmt(SysProc *sp, ExpressionList *el);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct Factor : public Term {

    Factor *setNot();

    Factor *setNeg();

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct CallFactor : public Factor {
    Name *nm;
    ArgsList *al;

    CallFactor(Name *nm, ArgsList *al);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct ConstFactor : public Factor {
    ConstValue *cv;

    explicit ConstFactor(ConstValue *cv);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct IndexFactor : public Factor {
    Name *nm;
    Expression *expr;

    IndexFactor(Name *nm, Expression *expr);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct MemberFactor : public Factor {
    Name *nm1;
    Name *nm2;

    MemberFactor(Name *nm1, Name *nm2);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct NameFactor : public Factor {
    Name *nm;

    explicit NameFactor(Name *nm);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct SysFunc : public ASTNode {
    std::string str;

    explicit SysFunc(std::string str);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct SysFuncCallFactor : public Factor {
    SysFunc *sf;
    ArgsList *al;

    SysFuncCallFactor(SysFunc *sf, ArgsList *al);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct SysFuncFactor : public Factor {
    SysFunc *sf;

    explicit SysFuncFactor(SysFunc *sf);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct ParenthesesFactor : public Factor {
    Expression *expr;

    explicit ParenthesesFactor(Expression *expr);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct ReadProcStmt : public ProcStmt {
    Factor *f;

    explicit ReadProcStmt(Factor *f);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct GotoStmt : public Stmt {
    int label;

    explicit GotoStmt(const std::string& str);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct ForStmt : public Stmt {
    Name *nm;
    Expression *expr;
    Direction *dir;
    Stmt *st;

    ForStmt(Name *nm, Expression *expr, Direction *dir, Stmt *st);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct AssignStmt : public Stmt {
    LeftValue *lv;
    Expression *expr;

    AssignStmt(LeftValue *lv, Expression *expr);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct CaseStmt : public Stmt {
    Expression *expr;
    CaseExprList *cel;

    CaseStmt(Expression *expr, CaseExprList *cel);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct WhileStmt : public Stmt {
    Expression *expr;
    Stmt *st;

    WhileStmt(Expression *expr, Stmt *st);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct Routine  : public ASTNode{
    RoutineHead *rh;
    RoutineBody *rb;

    Routine(RoutineHead *rh, RoutineBody *rb);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct RoutineBody : public ASTNode {
    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct CompoundStmt : public RoutineBody, public Stmt {
    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct StmtList : public CompoundStmt {
    std::vector<Stmt *> vec;

    void pushBack(Stmt *st);

    StmtList();

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct LabelPart  : public ASTNode{
    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct TypePart : public ASTNode {
    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct VarPart : public ASTNode {
    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct TypeDecl : public ASTNode {
    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct VarDecl : public ASTNode {
    NameList *nl;
    TypeDecl *td;

    VarDecl(NameList *nl, TypeDecl *td);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct VarDeclList : public VarPart {
    std::vector<VarDecl *> vec;

    void pushBack(VarDecl *vd);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct RoutineHead : public ASTNode {
    LabelPart *lp;
    ConstPart *cp;
    TypePart *tp;
    VarPart *vp;
    RoutinePart *rp;

    RoutineHead(LabelPart *lp, ConstPart *cp, TypePart *tp, VarPart *vp, RoutinePart *rp);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct RoutineDecl : public ASTNode {
protected:
    Routine *rt;

    explicit RoutineDecl(Routine *rt);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct Parameters : public ASTNode {
    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct ParaDeclList : public Parameters {
    std::vector<ParaTypeList *> vec;

    void pushBack(ParaTypeList *ptl);

    ParaDeclList();

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct _Function : public RoutineDecl {
    FunctionHead *fh;

    _Function(FunctionHead *fh, Routine *rt);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct FunctionHead : public ASTNode {
    Name *nm;
    Parameters *para;

    FunctionHead(Name *nm, Parameters *para);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct Procedure : public RoutineDecl {

    Procedure(ProcedureHead *ph, Routine *rt);

private:
    ProcedureHead *ph;

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct ProcedureHead : public ASTNode {
    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct RoutinePart : public ASTNode {
    std::vector<RoutineDecl *> vec;

    void pushBack(RoutineDecl *rd);

    RoutinePart();

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct SysProc : public ASTNode {
    std::string proc;

    explicit SysProc(std::string proc);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct TypeDeclList : public TypePart {
    std::vector<TypeDefinition *> vec;

    void pushBack(TypeDefinition *td);

    TypeDeclList();

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct TypeDefinition : public ASTNode {
    Name *nm;
    TypeDecl *td;

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct SimpleType : public TypeDecl {
    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct _ArrayType : public TypeDecl {
    SimpleType *st;
    TypeDecl *td;

    _ArrayType(SimpleType *st, TypeDecl *td);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct SysType : public SimpleType {
    std::string tp;

    explicit SysType(const std::string &tp);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct RecordType : public ASTNode {
    FieldDeclList *fdl;

    explicit RecordType(FieldDeclList *fdl);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct FieldDecl : public ASTNode {
    NameList *nl;
    TypeDecl *td;

    FieldDecl(NameList *nl, TypeDecl *td);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct FieldDeclList : public ASTNode {
    std::vector<FieldDecl *> vec;

    void pushBack(FieldDecl *fd);

    FieldDeclList();

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct CustomType : public SimpleType {
    Name *nm;

    explicit CustomType(Name *nm);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct EnumType : public SimpleType {
    NameList *nl;

    explicit EnumType(NameList *nl);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct RangeType : public SimpleType {
    ConstValue *l;
    ConstValue *r;

    RangeType(ConstValue *l, ConstValue *r);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct VarParaList : public ASTNode {
    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct ParaTypeList : public ASTNode {
    VarParaList *vpl;
    SimpleType *st;

    ParaTypeList(VarParaList *vpl, SimpleType *st);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct NameList : public ParaTypeList {
    std::vector<Name *> vec;

    void pushBack(Name *nm);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

#endif //SPL_ASTNODE_H