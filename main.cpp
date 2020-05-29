#include <iostream>
#include "ASTNode.h"
#include "parser.cpp"

llvm::LLVMContext context;
llvm::IRBuilder<> builder(context);
llvm::Module module("basic_module", context);
#include <llvm/IR/Value.h>
#include "ASTNode.h"

llvm::Function *startFunc = NULL;
Program *program = NULL;
int main() {
    yyparse();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
