//
// Created by gster on 6/2/20.
//

#ifndef SPL_UTILITY_H
#define SPL_UTILITY_H

#include "llvm/IR/Type.h"
#include "ASTNode.h"

namespace ASTUtilitiy {

    void startBlock(const ASTContext &astContext);

    llvm::Value *createCast(llvm::Value *value, llvm::Type *type);

    std::string getTypeName(llvm::Type *type);
}

#endif //SPL_UTILITY_H
