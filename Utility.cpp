//
// Created by gster on 6/2/20.
//

#include <iostream>
#include "Utility.h"
#include "ASTNode.h"

void ASTUtility::startBlock(const ASTContext &astContext) {
    llvm::Function *llvmFunction = astContext.currentFunction->llvmFunction;
    auto bb = llvm::BasicBlock::Create(context, "entry", llvmFunction);
    builder.SetInsertPoint(bb);
}

llvm::Value *ASTUtility::createCast(llvm::Value *value, llvm::Type *type) {
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
        std::cerr << "no viable conversion from '" + ASTUtility::getTypeName(valType)
                     + "' to '" + ASTUtility::getTypeName(type) + "'" << std::endl;
        return nullptr;
    }
}

std::string ASTUtility::getTypeName(llvm::Type *type) {
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

llvm::Constant *ASTUtility::getInitial(llvm::Type *type) {
    if (type->isDoubleTy()) {
        return llvm::ConstantFP::get(builder.getDoubleTy(), 0);
    } else if (type->isIntegerTy(64)) {
        return builder.getInt64(0);
    } else if (type->isIntegerTy(8)) {
        return builder.getInt8(0);
    } else {
        std::cerr << "no initializer for '" + getTypeName(type) + "'" << std::endl;
        return nullptr;
    }
}
