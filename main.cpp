#include <iostream>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/Transforms/InstCombine/InstCombine.h>
#include <llvm/Transforms/Scalar/GVN.h>

#include "ASTNode.h"
#include "parser.hpp"

llvm::LLVMContext context;
llvm::IRBuilder<> builder(context);
llvm::Module module("basic_module", context);
Program *program = NULL;
llvm::Function *startFunc;
std::string errorMsg;

int main() {
    yyparse();
    llvm::legacy::PassManager pm;
    pm.add(llvm::createPrintModulePass(llvm::outs()));
    ASTContext astContext;
    astContext.addType("int",builder.getInt64Ty());
    astContext.addType("char",builder.getInt8Ty());
    astContext.addType("real",builder.getDoubleTy());
    astContext.addType("bool",builder.getInt1Ty());
    program->codeGen(astContext);
    pm.run(module);
    return 0;
}
