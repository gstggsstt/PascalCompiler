#include <iostream>
#include "ASTNode.h"
#include "parser.cpp"

llvm::LLVMContext context;
llvm::IRBuilder<> builder(context);
llvm::Module module("basic_module", context);

int main() {
    yyparse();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
