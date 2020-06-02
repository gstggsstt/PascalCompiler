//
// Created by gster on 6/2/20.
//

#include <iostream>
#include "Utility.h"

void ASTUtilitiy::startBlock(const ASTContext &astContext) {
    llvm::Function *llvmFunction = astContext.currentFunction->llvmFunction;
    auto bb = llvm::BasicBlock::Create(context, "entry", llvmFunction);
    builder.SetInsertPoint(bb);
}

llvm::Value *ASTUtilitiy::createCast(llvm::Value *value, llvm::Type *type) {
    llvm::Type *valType = value->getType();
    if (valType == type ||
        type->isDoubleTy() && valType->isDoubleTy() ||
        type->isIntegerTy(64) && valType->isIntegerTy(64))
        return value;
    else if (type->isDoubleTy() && valType->isIntegerTy(64))
        return builder.CreateSIToFP(value, type);
    else if (type->isIntegerTy(64) && valType->isDoubleTy())
        return builder.CreateFPToSI(value, type);
    else {
        std::cerr << "no viable conversion from '" + ASTUtilitiy::getTypeName(valType)
                     + "' to '" + ASTUtilitiy::getTypeName(type) + "'" << std::endl;
        return nullptr;
    }
}

std::string ASTUtilitiy::getTypeName(llvm::Type *type) {
    if(type->isDoubleTy()){
        return "real";
    }else if(type->isIntegerTy(64)){
        return "int";
    }if(type->isVoidTy()){
        return "void";
    }else if(type->isIntegerTy(8)){
        return "char";
    }else if(type->isIntegerTy(1)){
        return "bool";
    }else{
        return "unknow";
    }
}
