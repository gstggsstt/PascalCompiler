#include <iostream>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/Transforms/InstCombine/InstCombine.h>
#include <llvm/Transforms/Scalar/GVN.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/IR/Module.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Bitcode/BitcodeWriter.h>
#include <llvm/Support/FileSystem.h>

#include "ASTNode.h"
#include "lexer.hpp"
#include "parser.hpp"
#include "SystemCall.h"


llvm::LLVMContext context;
llvm::IRBuilder<> builder(context);
llvm::Module module("basic_module", context);
Program *program = nullptr;
llvm::Function *startFunc;
std::string errorMsg;

void GenerateIRFile(){
    std::error_code EC;
    llvm::raw_fd_ostream OS("module.bc",EC);
    llvm::WriteBitcodeToFile(module, OS);
    OS.flush();
}

int main(int argc, char ** argv) {

    /*
     * Usage: one argument, input filename
     * Example: ./SPL res/gcd.pas
     */

    yyin = fopen(argv[1],"r");
    if(yyin==NULL) return 0;
    else std::cout << "read from " << argv[1] << std::endl;
    if(yyparse()) return 0;

    ASTContext astContext;
    llvm::InitializeNativeTarget();
    llvm::InitializeNativeTargetAsmPrinter();
    llvm::InitializeNativeTargetAsmParser();
    llvm::ExecutionEngine *ee = llvm::EngineBuilder(std::unique_ptr<llvm::Module>(&module)).create();

    addSystemFuncRead(module, *ee, builder, astContext);
    addSystemFuncWrite(module, *ee, builder,astContext);
    program->codeGen(astContext);

    llvm::legacy::PassManager pm;
    pm.add(llvm::createPrintModulePass(llvm::outs()));
    pm.run(module);

    GenerateIRFile();

    std::vector<llvm::GenericValue> args;
    ee->finalizeObject();

    std::cout << "##### Function output #####" << std::endl;
    llvm::GenericValue v = ee->runFunction(startFunc, args);
    std::cout << std::endl;
    std::cout << "##### Function end #####" << std::endl;
    return 0;
}
