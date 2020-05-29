#include <iostream>
#include <llvm/IR/Value.h>
#include "ASTNode.h"

llvm::LLVMContext &context = getGlobalContext();
llvm::Module module("test",context);
IRBuilder<> builder(context);
llvm::Function *startFunc = NULL;
std::string errorMsg;
Program *program = NULL;
int main() {
    llvm::Value* xx;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
