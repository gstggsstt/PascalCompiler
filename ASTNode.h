//
// Created by gster on 5/23/20.
//

#ifndef SPL_ASTNODE_H
#define SPL_ASTNODE_H

#include <string>
#include <llvm/IR/Value.h>
#include <llvm/IR/IRBuilder.h>

static llvm::LLVMContext Context;
static llvm::IRBuilder<> Builder(Context);
static std::unique_ptr<llvm::Module> Module;
static std::map<std::string, llvm::Value> NamedValues;

class ASTNode {
protected:
public:
    std::string type;
    ASTNode(){};
    virtual llvm::Value* codeGen() = 0;
};


#endif //SPL_ASTNODE_H
