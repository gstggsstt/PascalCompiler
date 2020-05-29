#include <iostream>
#include "ASTNode.h"

llvm::LLVMContext context;
llvm::IRBuilder<> builder(context);
llvm::Module module("basic_module", context);

int main() {
    llvm::Value* xx;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
