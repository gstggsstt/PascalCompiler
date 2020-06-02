//
// Created by gster on 5/24/20.
//

#ifndef SPL_NODETYPES_H
#define SPL_NODETYPES_H

struct ASTContext;
struct ASTFunction;
struct ASTNode;
struct ArgsList;
struct ArrayType;
struct AssignStmt;
struct BinaryExpr;
struct CalcExpr;
struct CallFactor;
struct CallProcStmt;
struct CaseExpr;
struct CaseExprList;
struct CaseStmt;
struct CompoundStmt;
struct ConstCharValue;
struct ConstExprList;
struct ConstFactor;
struct ConstIntValue;
struct ConstPart;
struct ConstRealValue;
struct ConstValue;
struct ConstValueCaseExpr;
struct ConstValueDecl;
struct CustomType;
struct Direction;
struct ElseClause;
struct EnumType;
struct Expr;
struct Expression;
struct ExpressionList;
struct Factor;
struct FieldDecl;
struct FieldDeclList;
struct ForStmt;
struct Function;
struct FunctionHead;
struct GotoStmt;
struct IfStmt;
struct IndexFactor;
struct IndexLeftValue;
struct LabelPart;
struct LeftValue;
struct MemberFactor;
struct MemberLeftValue;
struct NameCaseExpr;
struct NameFactor;
struct NameLeftValue;
struct NameList;
struct NameProcStmt;
struct NamedRangeType;
struct ParaDeclList;
struct ParaTypeList;
struct Parameters;
struct ParenthesesFactor;
struct ProcStmt;
struct Procedure;
struct ProcedureHead;
struct Program;
struct ProgramHead;
struct RangeType;
struct ReadProcStmt;
struct RecordType;
struct RepeatStmt;
struct Routine;
struct RoutineBody;
struct RoutineDecl;
struct RoutineHead;
struct RoutinePart;
struct SimpleType;
struct Stmt;
struct StmtList;
struct SysCallProcStmt;
struct SysFuncCallFactor;
struct SysFuncFactor;
struct SysType;
struct Term;
struct TypeDecl;
struct TypeDeclList;
struct TypeDefinition;
struct TypePart;
struct VarDecl;
struct VarDeclList;
struct VarParaList;
struct VarPart;
struct WhileStmt;

namespace ASTClassName {
    [[maybe_unused]] const std::string ASTContext = "ASTContext";
    [[maybe_unused]] const std::string ASTFunction = "ASTFunction";
    [[maybe_unused]] const std::string ASTNode = "ASTNode";
    [[maybe_unused]] const std::string ArgsList = "ArgsList";
    [[maybe_unused]] const std::string ArrayType = "ArrayType";
    [[maybe_unused]] const std::string AssignStmt = "AssignStmt";
    [[maybe_unused]] const std::string BinaryExpr = "BinaryExpr";
    [[maybe_unused]] const std::string CalcExpr = "CalcExpr";
    [[maybe_unused]] const std::string CallFactor = "CallFactor";
    [[maybe_unused]] const std::string CallProcStmt = "CallProcStmt";
    [[maybe_unused]] const std::string CaseExpr = "CaseExpr";
    [[maybe_unused]] const std::string CaseExprList = "CaseExprList";
    [[maybe_unused]] const std::string CaseStmt = "CaseStmt";
    [[maybe_unused]] const std::string CompoundStmt = "CompoundStmt";
    [[maybe_unused]] const std::string ConstCharValue = "ConstCharValue";
    [[maybe_unused]] const std::string ConstExprList = "ConstExprList";
    [[maybe_unused]] const std::string ConstFactor = "ConstFactor";
    [[maybe_unused]] const std::string ConstIntValue = "ConstIntValue";
    [[maybe_unused]] const std::string ConstPart = "ConstPart";
    [[maybe_unused]] const std::string ConstRealValue = "ConstRealValue";
    [[maybe_unused]] const std::string ConstValue = "ConstValue";
    [[maybe_unused]] const std::string ConstValueCaseExpr = "ConstValueCaseExpr";
    [[maybe_unused]] const std::string ConstValueDecl = "ConstValueDecl";
    [[maybe_unused]] const std::string CustomType = "CustomType";
    [[maybe_unused]] const std::string Direction = "Direction";
    [[maybe_unused]] const std::string ElseClause = "ElseClause";
    [[maybe_unused]] const std::string EnumType = "EnumType";
    [[maybe_unused]] const std::string Expr = "Expr";
    [[maybe_unused]] const std::string Expression = "Expression";
    [[maybe_unused]] const std::string ExpressionList = "ExpressionList";
    [[maybe_unused]] const std::string Factor = "Factor";
    [[maybe_unused]] const std::string FieldDecl = "FieldDecl";
    [[maybe_unused]] const std::string FieldDeclList = "FieldDeclList";
    [[maybe_unused]] const std::string ForStmt = "ForStmt";
    [[maybe_unused]] const std::string Function = "Function";
    [[maybe_unused]] const std::string FunctionHead = "FunctionHead";
    [[maybe_unused]] const std::string GotoStmt = "GotoStmt";
    [[maybe_unused]] const std::string IfStmt = "IfStmt";
    [[maybe_unused]] const std::string IndexFactor = "IndexFactor";
    [[maybe_unused]] const std::string IndexLeftValue = "IndexLeftValue";
    [[maybe_unused]] const std::string LabelPart = "LabelPart";
    [[maybe_unused]] const std::string LeftValue = "LeftValue";
    [[maybe_unused]] const std::string MemberFactor = "MemberFactor";
    [[maybe_unused]] const std::string MemberLeftValue = "MemberLeftValue";
    [[maybe_unused]] const std::string NameCaseExpr = "NameCaseExpr";
    [[maybe_unused]] const std::string NameFactor = "NameFactor";
    [[maybe_unused]] const std::string NameLeftValue = "NameLeftValue";
    [[maybe_unused]] const std::string NameList = "NameList";
    [[maybe_unused]] const std::string NameProcStmt = "NameProcStmt";
    [[maybe_unused]] const std::string NamedRangeType = "NamedRangeType";
    [[maybe_unused]] const std::string ParaDeclList = "ParaDeclList";
    [[maybe_unused]] const std::string ParaTypeList = "ParaTypeList";
    [[maybe_unused]] const std::string Parameters = "Parameters";
    [[maybe_unused]] const std::string ParenthesesFactor = "ParenthesesFactor";
    [[maybe_unused]] const std::string ProcStmt = "ProcStmt";
    [[maybe_unused]] const std::string Procedure = "Procedure";
    [[maybe_unused]] const std::string ProcedureHead = "ProcedureHead";
    [[maybe_unused]] const std::string Program = "Program";
    [[maybe_unused]] const std::string ProgramHead = "ProgramHead";
    [[maybe_unused]] const std::string RangeType = "RangeType";
    [[maybe_unused]] const std::string ReadProcStmt = "ReadProcStmt";
    [[maybe_unused]] const std::string RecordType = "RecordType";
    [[maybe_unused]] const std::string RepeatStmt = "RepeatStmt";
    [[maybe_unused]] const std::string Routine = "Routine";
    [[maybe_unused]] const std::string RoutineBody = "RoutineBody";
    [[maybe_unused]] const std::string RoutineDecl = "RoutineDecl";
    [[maybe_unused]] const std::string RoutineHead = "RoutineHead";
    [[maybe_unused]] const std::string RoutinePart = "RoutinePart";
    [[maybe_unused]] const std::string SimpleType = "SimpleType";
    [[maybe_unused]] const std::string Stmt = "Stmt";
    [[maybe_unused]] const std::string StmtList = "StmtList";
    [[maybe_unused]] const std::string SysCallProcStmt = "SysCallProcStmt";
    [[maybe_unused]] const std::string SysFuncCallFactor = "SysFuncCallFactor";
    [[maybe_unused]] const std::string SysFuncFactor = "SysFuncFactor";
    [[maybe_unused]] const std::string SysType = "SysType";
    [[maybe_unused]] const std::string Term = "Term";
    [[maybe_unused]] const std::string TypeDecl = "TypeDecl";
    [[maybe_unused]] const std::string TypeDeclList = "TypeDeclList";
    [[maybe_unused]] const std::string TypeDefinition = "TypeDefinition";
    [[maybe_unused]] const std::string TypePart = "TypePart";
    [[maybe_unused]] const std::string VarDecl = "VarDecl";
    [[maybe_unused]] const std::string VarDeclList = "VarDeclList";
    [[maybe_unused]] const std::string VarParaList = "VarParaList";
    [[maybe_unused]] const std::string VarPart = "VarPart";
    [[maybe_unused]] const std::string WhileStmt = "WhileStmt";
};


#endif //SPL_NODETYPES_H
