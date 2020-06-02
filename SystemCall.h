//
// Created by buttshark on 6/2/20.
//

#ifndef SPL_SYSTEMCALL_H
#define SPL_SYSTEMCALL_H
#include <iostream>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/Transforms/InstCombine/InstCombine.h>
#include <llvm/Transforms/Scalar/GVN.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/ExecutionEngine/GenericValue.h>

#include "ASTNode.h"
#include "parser.hpp"

void addSystemFuncWriteLn(llvm::Module &mdl, llvm::ExecutionEngine &ee, llvm::IRBuilder<> &bdr,ASTContext &astContext);
void addSystemFuncWrite(llvm::Module &mdl, llvm::ExecutionEngine &ee, llvm::IRBuilder<> &bdr,ASTContext &astContext);
void addSystemFuncRead(llvm::Module &mdl, llvm::ExecutionEngine &ee, llvm::IRBuilder<> &bdr,ASTContext &astContext);

#endif //SPL_SYSTEMCALL_H
