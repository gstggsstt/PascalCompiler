//
// Created by gster on 5/23/20.
//

#ifndef SPL_ASTNODE_H
#define SPL_ASTNODE_H

#include <string>
#include <vector>
#include <llvm/IR/Value.h>
#include <llvm/IR/IRBuilder.h>
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
extern std::string errorMsg;
// extern Program *program;
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
};

struct ConstValueDecl{
    std::string name;
    ConstValue* value;

    ConstValueDecl(const std::string &name, ConstValue *value);
};

struct ConstValue : public ASTNode {
    std::string typeName;

    virtual ConstValue *setNeg() = 0;

    llvm::Value *codeGen(ASTContext &astContext) override;
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

struct Program : public ASTNode {
    ProgramHead *ph;
    Routine *rt;

    Program(ProgramHead *ph, Routine *rt);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct ProgramHead : public ASTNode {
    std::string nm;

    explicit ProgramHead(std::string nm);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct Stmt : public ASTNode {
    int label;
    bool hasLabel;

    Stmt();

    explicit Stmt(const std::string &str);

    llvm::Value *codeGen(ASTContext &astContext) override;

    virtual void addLabel(std::string label);
};

struct CaseExpr : public ASTNode {
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
    std::string nm;

    NameCaseExpr(std::string nm, Stmt *st);

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

    explicit ElseClause(Stmt *st);

    ElseClause();

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct IfStmt : public Stmt {
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
    std::string nm;

    explicit NameLeftValue(std::string nm);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct IndexLeftValue : public LeftValue {
    std::string nm;
    Expression *expr;

    IndexLeftValue(std::string nm, Expression *expr);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct MemberLeftValue : public LeftValue {
    std::string nm1;
    std::string nm2;

    MemberLeftValue(std::string nm1, std::string nm2);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct RepeatStmt : public Stmt {
    StmtList *sl;
    Expression *expr;

    RepeatStmt(StmtList *sl, Expression *expr);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct ProcStmt : public Stmt {
    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct NameProcStmt : public ProcStmt {
    std::string nm;

    explicit NameProcStmt(std::string nm);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct CallProcStmt : public ProcStmt {
    std::string nm;
    ArgsList *al;

    CallProcStmt(std::string nm, ArgsList *al);

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
    std::string nm;
    ArgsList *al;

    CallFactor(std::string nm, ArgsList *al);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct ConstFactor : public Factor {
    ConstValue *cv;

    explicit ConstFactor(ConstValue *cv);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct IndexFactor : public Factor {
    std::string nm;
    Expression *expr;

    IndexFactor(std::string nm, Expression *expr);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct MemberFactor : public Factor {
    std::string nm1;
    std::string nm2;

    MemberFactor(std::string nm1, std::string nm2);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct NameFactor : public Factor {
    std::string nm;

    explicit NameFactor(std::string nm);

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
    std::string nm;
    Expression *expr;
    Direction *dir;
    Expression *toExpr;
    Stmt *st;

    ForStmt(const std::string &nm, Expression *expr, Direction *dir, Expression *toExpr, Stmt *st);

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

struct Function : public RoutineDecl {
    FunctionHead *fh;

    Function(FunctionHead *fh, Routine *rt);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct FunctionHead : public ASTNode {
    std::string nm;
    Parameters *para;
    SimpleType *st;

    FunctionHead(const std::string &nm, Parameters *para, SimpleType *st);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct Procedure : public RoutineDecl {
    ProcedureHead *ph;
    Procedure(ProcedureHead *ph, Routine *rt);
    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct ProcedureHead : public ASTNode {
    std::string nm;
    Parameters *para;

    ProcedureHead(const std::string &nm, Parameters *para);

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
    std::string nm;
    TypeDecl *td;

    TypeDefinition(std::string nm, TypeDecl *td);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct SimpleType : public TypeDecl {
    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct ArrayType : public TypeDecl {
    SimpleType *st;
    TypeDecl *td;

    ArrayType(SimpleType *st, TypeDecl *td);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct SysType : public SimpleType {
    std::string tp;

    explicit SysType(const std::string &tp);

    llvm::Value *codeGen(ASTContext &astContext) override;
};

struct RecordType : public TypeDecl {
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
    std::string nm;

    explicit CustomType(std::string nm);

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

struct NamedRangeType : public SimpleType {
    std::string cv1;
    std::string cv2;

    NamedRangeType(std::string cv1, std::string cv2);

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

struct NameList : public VarParaList {
    std::vector<std::string > vec;

    void pushBack(std::string nm);

    NameList();

    llvm::Value *codeGen(ASTContext &astContext) override;
};

#endif //SPL_ASTNODE_H
