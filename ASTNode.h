//
// Created by gster on 5/23/20.
//

#ifndef SPL_ASTNODE_H
#define SPL_ASTNODE_H

#include <string>
#include <vector>
#include <llvm/IR/Value.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Verifier.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/ToolOutputFile.h>
#include <llvm/Support/FormattedStream.h>
#include <llvm/Support/Host.h>
#include <llvm/Support/TargetRegistry.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Analysis/Passes.h>
#include <llvm/Transforms/Scalar.h>
#include "NodeTypes.h"

extern llvm::LLVMContext context;
extern llvm::IRBuilder<> builder;
extern llvm::Module module;
extern llvm::Function *startFunc;

llvm::Value* createCast(llvm::Value *value,llvm::Type *type);
void startBlock(const ASTContext &astContext);

struct ASTFunction {
public:
	std::string name;
	llvm::Function *llvmFunction;
	llvm::Type *returnType;
	std::vector<llvm::Type*> argTypes;
	llvm::Value *returnVal;
	void printIR() const;
	ASTFunction(std::string name, llvm::Function *llvmFunction, llvm::Type *returnType, std::vector<llvm::Type*> &argTypes);
};

struct ASTContext {
	ASTContext *parent;
	std::map<std::string,llvm::Type*> typeTable;
	std::map<std::string,ASTFunction*> functionTable;
	std::map<std::string,llvm::Value*> varTable;

public:
	ASTFunction *currentFunction;


    explicit ASTContext(ASTContext *p = nullptr);

    void createSysFunc();
	llvm::Type * getType(const std::string &name);
	ASTFunction * getFunction(const std::string &name);
	llvm::Value * getVar(const std::string &name);
	bool addFunction(const std::string &name, ASTFunction *function);
	bool addVar(const std::string &name, llvm::Value *value);
	bool addType(const std::string &name, llvm::Type *type); // Like typeOf("real"),change string to llvm::Type
};//Used to create symbol table and access link,when create a new block by BEGIN END,create an AST context.

struct ASTNode {
public:
    virtual std::string getClassName() = 0;
    virtual llvm::Value *codeGen(ASTContext &astContext);
};

struct ArgsList : public ASTNode {

    std::vector<Expression *> vec;

    void pushBack(Expression *expr);

    ArgsList();

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct ConstValueDecl : public ASTNode {
    std::string name;
    ConstValue* value;

    ConstValueDecl(std::string name, ConstValue *value);
    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct ConstValue : public ASTNode {
    std::string typeName;

    virtual ConstValue *setNeg() = 0;

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct ConstIntValue : public ConstValue {

    int val;

    ConstValue *setNeg() override;

    explicit ConstIntValue(const std::string &val);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct ConstRealValue : public ConstValue {

    double val;

    ConstValue *setNeg() override;

    explicit ConstRealValue(const std::string &val);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct ConstCharValue : public ConstValue {

    char val;

    ConstValue *setNeg() override;

    explicit ConstCharValue(const std::string &val);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct ConstExprList : public ASTNode {

    std::vector<ConstValueDecl *> vec;

    void pushBack(ConstValueDecl *ce);

    ConstExprList();

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct ConstPart : public ASTNode {

    ConstExprList *cel;

    explicit ConstPart(ConstExprList *cel);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct Direction : public ASTNode {

    std::string dir;

    explicit Direction(std::string dir);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct Expression  : public ASTNode{

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct Expr : public Expression {

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct Term : public Expr {

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct CalcExpr : public Term {

    Expression *l;
    Expression *r;
    std::string op;

    CalcExpr(Expression *l, Expression *r, std::string op);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct BinaryExpr : public Term {
	Expression *l;
    Expression *r;
    std::string op;
public:
	BinaryExpr(Expression *l, Expression *r, std::string op);
    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct ExpressionList : public ASTNode {
    std::vector<Expression *> vec;

    void pushBack(Expression *expr);

    ExpressionList();

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct Program : public ASTNode {
    ProgramHead *ph;
    Routine *rt;

    Program(ProgramHead *ph, Routine *rt);

    llvm::Value *codeGen(ASTContext &astContext) override;

    std::string getClassName() override;
};

struct ProgramHead : public ASTNode {
    std::string nm;

    explicit ProgramHead(std::string nm);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct Stmt : public ASTNode {
    int label;
    bool hasLabel;

    Stmt();

    explicit Stmt(const std::string &str);

    llvm::Value *codeGen(ASTContext &astContext) override;

    virtual void addLabel(const std::string &);
    std::string getClassName() override;
};

struct CaseExpr : public ASTNode {
    Stmt *st;

    explicit CaseExpr(Stmt *st);

    llvm::Value *codeGen(ASTContext &astContext) override;
    virtual llvm::Value *codeGen2(ASTContext &astContext);
    std::string getClassName() override;
};

struct ConstValueCaseExpr : public CaseExpr {
    ConstValue *cv;

    ConstValueCaseExpr(ConstValue *cv, Stmt *st);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct NameCaseExpr : public CaseExpr {
    std::string nm;

    NameCaseExpr(std::string nm, Stmt *st);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct CaseExprList : public ASTNode {
    std::vector<CaseExpr *> vec;

    void pushBack(CaseExpr *ce);

    CaseExprList();

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct ElseClause : public ASTNode {
    Stmt *st;

    explicit ElseClause(Stmt *st);

    ElseClause();

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct IfStmt : public Stmt {
    Expression *expr;
    Stmt *st;
    ElseClause *ec;

    IfStmt(Expression *expr, Stmt *st, ElseClause *ec);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct LeftValue : public ASTNode {
    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct NameLeftValue : public LeftValue {
    std::string nm;

    explicit NameLeftValue(std::string nm);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct IndexLeftValue : public LeftValue {
    std::string nm;
    Expression *expr;

    IndexLeftValue(std::string nm, Expression *expr);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct MemberLeftValue : public LeftValue {
    std::string nm1;
    std::string nm2;

    MemberLeftValue(std::string nm1, std::string nm2);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct RepeatStmt : public Stmt {
    StmtList *sl;
    Expression *expr;

    RepeatStmt(StmtList *sl, Expression *expr);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct ProcStmt : public Stmt {
    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct NameProcStmt : public ProcStmt {
    std::string nm;

    explicit NameProcStmt(std::string nm);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct CallProcStmt : public ProcStmt {
    std::string nm;
    ArgsList *al;

    CallProcStmt(std::string nm, ArgsList *al);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct SysProcStmt : public ProcStmt {
    SysProc *sp;

    explicit SysProcStmt(SysProc *sp);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct SysCallProcStmt : public ProcStmt {
    SysProc *sp;
    ExpressionList *el;

    SysCallProcStmt(SysProc *sp, ExpressionList *el);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct Factor : public Term {
    bool neg;
    bool noT;

    Factor *setNot();

    Factor *setNeg();

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct CallFactor : public Factor {
    std::string nm;
    ArgsList *al;

    CallFactor(std::string nm, ArgsList *al);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct ConstFactor : public Factor {
    ConstValue *cv;

    explicit ConstFactor(ConstValue *cv);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct IndexFactor : public Factor {
    std::string nm;
    Expression *expr;

    IndexFactor(std::string nm, Expression *expr);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct MemberFactor : public Factor {
    std::string nm1;
    std::string nm2;

    MemberFactor(std::string nm1, std::string nm2);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct NameFactor : public Factor {
    std::string nm;

    explicit NameFactor(std::string nm);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct SysFunc : public ASTNode {
    std::string str;

    explicit SysFunc(std::string str);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct SysFuncCallFactor : public Factor {
    SysFunc *sf;
    ArgsList *al;

    SysFuncCallFactor(SysFunc *sf, ArgsList *al);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct SysFuncFactor : public Factor {
    SysFunc *sf;

    explicit SysFuncFactor(SysFunc *sf);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct ParenthesesFactor : public Factor {
    Expression *expr;

    explicit ParenthesesFactor(Expression *expr);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct ReadProcStmt : public ProcStmt {
    Factor *f;

    explicit ReadProcStmt(Factor *f);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct GotoStmt : public Stmt {
    int label;

    explicit GotoStmt(const std::string& str);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct ForStmt : public Stmt {
    std::string nm;
    Expression *expr;
    Direction *dir;
    Expression *toExpr;
    Stmt *st;

    ForStmt(std::string nm, Expression *expr, Direction *dir, Expression *toExpr, Stmt *st);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct AssignStmt : public Stmt {
    LeftValue *lv;
    Expression *expr;

    AssignStmt(LeftValue *lv, Expression *expr);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct CaseStmt : public Stmt {
    Expression *expr;
    CaseExprList *cel;

    CaseStmt(Expression *expr, CaseExprList *cel);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct WhileStmt : public Stmt {
    Expression *expr;
    Stmt *st;

    WhileStmt(Expression *expr, Stmt *st);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct Routine  : public ASTNode{
    RoutineHead *rh;
    RoutineBody *rb;

    Routine(RoutineHead *rh, RoutineBody *rb);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct RoutineBody : public ASTNode {
    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct CompoundStmt : public RoutineBody, public Stmt {
    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct StmtList : public CompoundStmt {
    std::vector<Stmt *> vec;

    void pushBack(Stmt *st);

    StmtList();

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct LabelPart  : public ASTNode{
    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct TypePart : public ASTNode {
    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct VarPart : public ASTNode {
    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct TypeDecl : public ASTNode {
    std::string declTp;

    TypeDecl();

    explicit TypeDecl(std::string decltp);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct VarDecl : public ASTNode {
    NameList *nl;
    TypeDecl *td;

    VarDecl(NameList *nl, TypeDecl *td);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct VarDeclList : public VarPart {
    std::vector<VarDecl *> vec;

    void pushBack(VarDecl *vd);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct RoutineHead : public ASTNode {
    LabelPart *lp;
    ConstPart *cp;
    TypePart *tp;
    VarPart *vp;
    RoutinePart *rp;

    RoutineHead(LabelPart *lp, ConstPart *cp, TypePart *tp, VarPart *vp, RoutinePart *rp);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct RoutineDecl : public ASTNode {
    Routine *rt;

    explicit RoutineDecl(Routine *rt);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct Parameters : public ASTNode {
    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct ParaDeclList : public Parameters {
    std::vector<ParaTypeList *> vec;

    void pushBack(ParaTypeList *ptl);

    ParaDeclList();

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct Function : public RoutineDecl {
    FunctionHead *fh;

    Function(FunctionHead *fh, Routine *rt);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct FunctionHead : public ASTNode {
    std::string nm;
    Parameters *para;
    SimpleType *st;

    FunctionHead(std::string nm, Parameters *para, SimpleType *st);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct Procedure : public RoutineDecl {
    ProcedureHead *ph;
    Procedure(ProcedureHead *ph, Routine *rt);
    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct ProcedureHead : public ASTNode {
    std::string nm;
    Parameters *para;

    ProcedureHead(std::string nm, Parameters *para);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct RoutinePart : public ASTNode {
    std::vector<RoutineDecl *> vec;

    void pushBack(RoutineDecl *rd);

    RoutinePart();

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct SysProc : public ASTNode {
    std::string proc;

    explicit SysProc(std::string proc);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct TypeDeclList : public TypePart {
    std::vector<TypeDefinition *> vec;

    void pushBack(TypeDefinition *td);

    TypeDeclList();

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct TypeDefinition : public ASTNode {
    std::string nm;
    TypeDecl *td;

    TypeDefinition(std::string nm, TypeDecl *td);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct SimpleType : public TypeDecl {
    explicit SimpleType(const std::string &decltp);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct ArrayType : public TypeDecl {
    SimpleType *st;
    TypeDecl *td;

    ArrayType(SimpleType *st, TypeDecl *td);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct SysType : public SimpleType {

    explicit SysType(const std::string &decltp);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct RecordType : public TypeDecl {
    FieldDeclList *fdl;

    explicit RecordType(FieldDeclList *fdl);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct FieldDecl : public ASTNode {
    NameList *nl;
    TypeDecl *td;

    FieldDecl(NameList *nl, TypeDecl *td);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct FieldDeclList : public ASTNode {
    std::vector<FieldDecl *> vec;

    void pushBack(FieldDecl *fd);

    FieldDeclList();

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct CustomType : public SimpleType {
    std::string nm;

    CustomType(std::string nm, const std::string &decltp);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct EnumType : public SimpleType {
    NameList *nl;

    EnumType(NameList *nl, const std::string &decltp);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct RangeType : public SimpleType {
    ConstValue *l;
    ConstValue *r;

    RangeType(ConstValue *l, ConstValue *r, const std::string &decltp);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct NamedRangeType : public SimpleType {
    std::string cv1;
    std::string cv2;

    NamedRangeType(std::string cv1, std::string cv2, const std::string &decltp);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct VarParaList : public ASTNode {
    bool ref;

    VarParaList();

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct ParaTypeList : public ASTNode {
    VarParaList *vpl;
    SimpleType *st;

    ParaTypeList(VarParaList *vpl, SimpleType *st);

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

struct NameList : public VarParaList {
    std::vector<std::string > vec;

    void pushBack(const std::string& nm);

    NameList();

    llvm::Value *codeGen(ASTContext &astContext) override;
    std::string getClassName() override;
};

#endif //SPL_ASTNODE_H
