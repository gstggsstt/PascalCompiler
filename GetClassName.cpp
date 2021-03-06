//
// Created by gster on 6/2/20.
//
#include "ASTNode.h"
std::string ArgsList::getClassName() { return ASTClassName::ArgsList;}
std::string ConstValueDecl::getClassName() { return ASTClassName::ConstValueDecl;}
std::string ConstValue::getClassName() { return ASTClassName::ConstValue;}
std::string ConstIntValue::getClassName() { return ASTClassName::ConstIntValue;}
std::string ConstRealValue::getClassName() { return ASTClassName::ConstRealValue;}
std::string ConstCharValue::getClassName() { return ASTClassName::ConstCharValue;}
std::string ConstExprList::getClassName() { return ASTClassName::ConstExprList;}
std::string ConstPart::getClassName() { return ASTClassName::ConstPart;}
std::string Direction::getClassName() { return ASTClassName::Direction;}
std::string Expression::getClassName() { return ASTClassName::Expression;}
std::string Expr::getClassName() { return ASTClassName::Expr;}
std::string Term::getClassName() { return ASTClassName::Term;}
std::string CalcExpr::getClassName() { return ASTClassName::CalcExpr;}
std::string BinaryExpr::getClassName() { return ASTClassName::BinaryExpr;}
std::string ExpressionList::getClassName() { return ASTClassName::ExpressionList;}
std::string Program::getClassName() { return ASTClassName::Program;}
std::string ProgramHead::getClassName() { return ASTClassName::ProgramHead;}
std::string Stmt::getClassName() { return ASTClassName::Stmt;}
std::string CaseExpr::getClassName() { return ASTClassName::CaseExpr;}
std::string ConstValueCaseExpr::getClassName() { return ASTClassName::ConstValueCaseExpr;}
std::string NameCaseExpr::getClassName() { return ASTClassName::NameCaseExpr;}
std::string CaseExprList::getClassName() { return ASTClassName::CaseExprList;}
std::string ElseClause::getClassName() { return ASTClassName::ElseClause;}
std::string IfStmt::getClassName() { return ASTClassName::IfStmt;}
std::string LeftValue::getClassName() { return ASTClassName::LeftValue;}
std::string NameLeftValue::getClassName() { return ASTClassName::NameLeftValue;}
std::string IndexLeftValue::getClassName() { return ASTClassName::IndexLeftValue;}
std::string MemberLeftValue::getClassName() { return ASTClassName::MemberLeftValue;}
std::string RepeatStmt::getClassName() { return ASTClassName::RepeatStmt;}
std::string ProcStmt::getClassName() { return ASTClassName::ProcStmt;}
std::string NameProcStmt::getClassName() { return ASTClassName::NameProcStmt;}
std::string CallProcStmt::getClassName() { return ASTClassName::CallProcStmt;}
std::string SysCallProcStmt::getClassName() { return ASTClassName::SysCallProcStmt;}
std::string Factor::getClassName() { return ASTClassName::Factor;}
std::string CallFactor::getClassName() { return ASTClassName::CallFactor;}
std::string ConstFactor::getClassName() { return ASTClassName::ConstFactor;}
std::string IndexFactor::getClassName() { return ASTClassName::IndexFactor;}
std::string MemberFactor::getClassName() { return ASTClassName::MemberFactor;}
std::string NameFactor::getClassName() { return ASTClassName::NameFactor;}
std::string SysFuncCallFactor::getClassName() { return ASTClassName::SysFuncCallFactor;}
std::string SysFuncFactor::getClassName() { return ASTClassName::SysFuncFactor;}
std::string ParenthesesFactor::getClassName() { return ASTClassName::ParenthesesFactor;}
std::string ReadProcStmt::getClassName() { return ASTClassName::ReadProcStmt;}
std::string GotoStmt::getClassName() { return ASTClassName::GotoStmt;}
std::string ForStmt::getClassName() { return ASTClassName::ForStmt;}
std::string AssignStmt::getClassName() { return ASTClassName::AssignStmt;}
std::string CaseStmt::getClassName() { return ASTClassName::CaseStmt;}
std::string WhileStmt::getClassName() { return ASTClassName::WhileStmt;}
std::string Routine::getClassName() { return ASTClassName::Routine;}
std::string RoutineBody::getClassName() { return ASTClassName::RoutineBody;}
std::string CompoundStmt::getClassName() { return ASTClassName::CompoundStmt;}
std::string StmtList::getClassName() { return ASTClassName::StmtList;}
std::string LabelPart::getClassName() { return ASTClassName::LabelPart;}
std::string TypePart::getClassName() { return ASTClassName::TypePart;}
std::string VarPart::getClassName() { return ASTClassName::VarPart;}
std::string TypeDecl::getClassName() { return ASTClassName::TypeDecl;}
std::string VarDecl::getClassName() { return ASTClassName::VarDecl;}
std::string VarDeclList::getClassName() { return ASTClassName::VarDeclList;}
std::string RoutineHead::getClassName() { return ASTClassName::RoutineHead;}
std::string RoutineDecl::getClassName() { return ASTClassName::RoutineDecl;}
std::string Parameters::getClassName() { return ASTClassName::Parameters;}
std::string ParaDeclList::getClassName() { return ASTClassName::ParaDeclList;}
std::string Function::getClassName() { return ASTClassName::Function;}
std::string FunctionHead::getClassName() { return ASTClassName::FunctionHead;}
std::string Procedure::getClassName() { return ASTClassName::Procedure;}
std::string ProcedureHead::getClassName() { return ASTClassName::ProcedureHead;}
std::string RoutinePart::getClassName() { return ASTClassName::RoutinePart;}
std::string TypeDeclList::getClassName() { return ASTClassName::TypeDeclList;}
std::string TypeDefinition::getClassName() { return ASTClassName::TypeDefinition;}
std::string SimpleType::getClassName() { return ASTClassName::SimpleType;}
std::string ArrayType::getClassName() { return ASTClassName::ArrayType;}
std::string SysType::getClassName() { return ASTClassName::SysType;}
std::string RecordType::getClassName() { return ASTClassName::RecordType;}
std::string FieldDecl::getClassName() { return ASTClassName::FieldDecl;}
std::string FieldDeclList::getClassName() { return ASTClassName::FieldDeclList;}
std::string CustomType::getClassName() { return ASTClassName::CustomType;}
std::string EnumType::getClassName() { return ASTClassName::EnumType;}
std::string RangeType::getClassName() { return ASTClassName::RangeType;}
std::string NamedRangeType::getClassName() { return ASTClassName::NamedRangeType;}
std::string VarParaList::getClassName() { return ASTClassName::VarParaList;}
std::string ParaTypeList::getClassName() { return ASTClassName::ParaTypeList;}
std::string NameList::getClassName() { return ASTClassName::NameList;}

