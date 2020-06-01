#include <iostream>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/Transforms/InstCombine/InstCombine.h>
#include <llvm/Transforms/Scalar/GVN.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/ExecutionEngine/GenericValue.h>

#include "ASTNode.h"
#include "parser.hpp"

llvm::LLVMContext context;
llvm::IRBuilder<> builder(context);
llvm::Module module("basic_module", context);
Program *program = nullptr;
llvm::Function *startFunc;
std::string errorMsg;

void intWriteLn(int64_t a) {
    std::cout << a << std::endl;
}
void doubleWriteLn(double_t a) {
    std::cout << a << std::endl;
}
void charWriteLn(int8_t a) {
    std::cout << a << std::endl;
}
void addSystemFunc(llvm::Module &mdl, llvm::ExecutionEngine &ee, llvm::IRBuilder<> &bdr) {
    std::vector<llvm::Type*> intArgs;
    std::vector<llvm::Type*> doubleArgs;
    std::vector<llvm::Type*> charArgs;
    intArgs.push_back(bdr.getInt64Ty());
    doubleArgs.push_back(bdr.getDoubleTy());
    charArgs.push_back(bdr.getInt8Ty());
    llvm::FunctionType *intType = llvm::FunctionType::get(bdr.getVoidTy(), intArgs, false);
    llvm::FunctionType *doubleType = llvm::FunctionType::get(bdr.getVoidTy(), doubleArgs, false);
    llvm::FunctionType *charType = llvm::FunctionType::get(bdr.getVoidTy(), charArgs, false);
    llvm::Function* intPrintLn = llvm::Function::Create(intType,llvm::GlobalValue::ExternalLinkage,"int_print",&mdl);
    llvm::Function* doublePrintLn = llvm::Function::Create(doubleType,llvm::GlobalValue::ExternalLinkage,"double_print",&mdl);
    llvm::Function* charPrintLn = llvm::Function::Create(charType,llvm::GlobalValue::ExternalLinkage,"char_print",&mdl);
    intPrintLn -> setCallingConv(llvm::CallingConv::C);
    doublePrintLn -> setCallingConv(llvm::CallingConv::C);
    charPrintLn -> setCallingConv(llvm::CallingConv::C);
    ee.addGlobalMapping((llvm::GlobalValue*)intPrintLn,(void*) &intWriteLn);
    ee.addGlobalMapping((llvm::GlobalValue*)doublePrintLn,(void*) &doubleWriteLn);
    ee.addGlobalMapping((llvm::GlobalValue*)charPrintLn,(void*) &charWriteLn);
}

int main() {

    yyparse();

    ASTContext astContext;
    program->codeGen(astContext);

    llvm::legacy::PassManager pm;
    pm.add(llvm::createPrintModulePass(llvm::outs()));
    pm.run(module);

    llvm::InitializeNativeTarget();
    llvm::InitializeNativeTargetAsmPrinter();
    llvm::InitializeNativeTargetAsmParser();

    std::string boom = "boom";
    llvm::ExecutionEngine *ee = llvm::EngineBuilder(std::unique_ptr<llvm::Module>(&module)).setErrorStr(&boom).setEngineKind(llvm::EngineKind::JIT).create();
    std::vector<llvm::GenericValue> args;
    ee->finalizeObject();
    llvm::GenericValue v = ee->runFunction(startFunc, args);
    return 0;
}
