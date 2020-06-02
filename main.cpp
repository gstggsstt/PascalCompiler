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
#include "SystemCall.h"

llvm::LLVMContext context;
llvm::IRBuilder<> builder(context);
llvm::Module module("basic_module", context);
Program *program = nullptr;
llvm::Function *startFunc;
std::string errorMsg;



int main() {

    yyparse();

    ASTContext astContext;
    llvm::InitializeNativeTarget();
    llvm::InitializeNativeTargetAsmPrinter();
    llvm::InitializeNativeTargetAsmParser();
    std::string boom = "boom";
    llvm::ExecutionEngine *ee = llvm::EngineBuilder(std::unique_ptr<llvm::Module>(&module)).setErrorStr(&boom).setEngineKind(llvm::EngineKind::JIT).create();
    addSystemFuncWriteLn(module, *ee, builder,astContext);
    program->codeGen(astContext);

    llvm::legacy::PassManager pm;
    pm.add(llvm::createPrintModulePass(llvm::outs()));
    pm.run(module);




    std::vector<llvm::GenericValue> args;
    ee->finalizeObject();
    llvm::GenericValue v = ee->runFunction(startFunc, args);
    return 0;
}
