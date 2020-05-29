#include <iostream>
#include "ASTNode.h"
#include "parser.cpp"
#include <llvm/IR/Value.h>

llvm::LLVMContext context;
llvm::IRBuilder<> builder(context);
llvm::Module module("basic_module", context);
Program *program = NULL;
int main() {
    yyparse();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
