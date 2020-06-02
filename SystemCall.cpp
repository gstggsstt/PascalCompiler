//
// Created by buttshark on 6/2/20.
//

#include "SystemCall.h"
void intWriteLn(int64_t a) {
    std::cout << a << std::endl;
}
void doubleWriteLn(double_t a) {
    std::cout << a << std::endl;
}
void charWriteLn(int8_t a) {
    std::cout << a << std::endl;
}
void intWrite(int64_t a) {
    std::cout << a;
}
void doubleWrite(double_t a) {
    std::cout << a;
}
void charWrite(int8_t a) {
    std::cout << a;
}
void addSystemFuncWriteLn(llvm::Module &mdl, llvm::ExecutionEngine &ee, llvm::IRBuilder<> &bdr,ASTContext &astContext) {
    std::vector<llvm::Type*> intArgs;
    std::vector<llvm::Type*> doubleArgs;
    std::vector<llvm::Type*> charArgs;
    intArgs.push_back(bdr.getInt64Ty());
    doubleArgs.push_back(bdr.getDoubleTy());
    charArgs.push_back(bdr.getInt8Ty());
    llvm::FunctionType *intType = llvm::FunctionType::get(bdr.getVoidTy(), intArgs, false);
    llvm::FunctionType *doubleType = llvm::FunctionType::get(bdr.getVoidTy(), doubleArgs, false);
    llvm::FunctionType *charType = llvm::FunctionType::get(bdr.getVoidTy(), charArgs, false);
    llvm::Function* intPrintLn = llvm::Function::Create(intType,llvm::GlobalValue::ExternalLinkage,"int_print_ln",&mdl);
    llvm::Function* doublePrintLn = llvm::Function::Create(doubleType,llvm::GlobalValue::ExternalLinkage,"double_print_ln",&mdl);
    llvm::Function* charPrintLn = llvm::Function::Create(charType,llvm::GlobalValue::ExternalLinkage,"char_print_ln",&mdl);
    intPrintLn -> setCallingConv(llvm::CallingConv::C);
    doublePrintLn -> setCallingConv(llvm::CallingConv::C);
    charPrintLn -> setCallingConv(llvm::CallingConv::C);
    ee.addGlobalMapping((llvm::GlobalValue*)intPrintLn, reinterpret_cast<void*>(&intWriteLn));
    ee.addGlobalMapping((llvm::GlobalValue*)doublePrintLn,reinterpret_cast<void*>(&doubleWriteLn));
    ee.addGlobalMapping((llvm::GlobalValue*)charPrintLn,reinterpret_cast<void*>(&charWriteLn));
    auto* intFunc = new ASTFunction("intWriteLn",intPrintLn,intType,intArgs);
    astContext.addFunction("intWriteLn",intFunc);
    auto* doubleFunc = new ASTFunction("doubleWriteLn",intPrintLn,intType,intArgs);
    astContext.addFunction("doubleWriteLn",doubleFunc);
    auto* charFunc = new ASTFunction("charWriteLn",intPrintLn,intType,intArgs);
    astContext.addFunction("charWriteLn",charFunc);
}

void addSystemFuncWrite(llvm::Module &mdl, llvm::ExecutionEngine &ee, llvm::IRBuilder<> &bdr,ASTContext &astContext) {
    std::vector<llvm::Type*> intArgs;
    std::vector<llvm::Type*> doubleArgs;
    std::vector<llvm::Type*> charArgs;
    intArgs.push_back(bdr.getInt64Ty());
    doubleArgs.push_back(bdr.getDoubleTy());
    charArgs.push_back(bdr.getInt8Ty());
    llvm::FunctionType *intType = llvm::FunctionType::get(bdr.getVoidTy(), intArgs, false);
    llvm::FunctionType *doubleType = llvm::FunctionType::get(bdr.getVoidTy(), doubleArgs, false);
    llvm::FunctionType *charType = llvm::FunctionType::get(bdr.getVoidTy(), charArgs, false);
    llvm::Function* intPrint = llvm::Function::Create(intType,llvm::GlobalValue::ExternalLinkage,"int_print",&mdl);
    llvm::Function* doublePrint = llvm::Function::Create(doubleType,llvm::GlobalValue::ExternalLinkage,"double_print",&mdl);
    llvm::Function* charPrint = llvm::Function::Create(charType,llvm::GlobalValue::ExternalLinkage,"char_print",&mdl);
    intPrint -> setCallingConv(llvm::CallingConv::C);
    doublePrint -> setCallingConv(llvm::CallingConv::C);
    charPrint -> setCallingConv(llvm::CallingConv::C);
    ee.addGlobalMapping((llvm::GlobalValue*)intPrint, reinterpret_cast<void*>(&intWrite));
    ee.addGlobalMapping((llvm::GlobalValue*)doublePrint,reinterpret_cast<void*>(&doubleWrite));
    ee.addGlobalMapping((llvm::GlobalValue*)charPrint,reinterpret_cast<void*>(&charWrite));
    auto* intFunc = new ASTFunction("intWrite",intPrint,intType,intArgs);
    astContext.addFunction("intWrite",intFunc);
    auto* doubleFunc = new ASTFunction("doubleWrite",intPrint,intType,intArgs);
    astContext.addFunction("doubleWrite",doubleFunc);
    auto* charFunc = new ASTFunction("charWrite",intPrint,intType,intArgs);
    astContext.addFunction("charWrite",charFunc);
}

void addSystemFuncRead(llvm::Module &mdl, llvm::ExecutionEngine &ee, llvm::IRBuilder<> &bdr,ASTContext &astContext) {
    std::vector<llvm::Type*> intArgs;
    std::vector<llvm::Type*> doubleArgs;
    std::vector<llvm::Type*> charArgs;
    intArgs.push_back(bdr.getInt64Ty());
    doubleArgs.push_back(bdr.getDoubleTy());
    charArgs.push_back(bdr.getInt8Ty());
    llvm::FunctionType *intType = llvm::FunctionType::get(bdr.getVoidTy(), intArgs, false);
    llvm::FunctionType *doubleType = llvm::FunctionType::get(bdr.getVoidTy(), doubleArgs, false);
    llvm::FunctionType *charType = llvm::FunctionType::get(bdr.getVoidTy(), charArgs, false);
    llvm::Function* intRead = llvm::Function::Create(intType, llvm::GlobalValue::ExternalLinkage, "int_read", &mdl);
    llvm::Function* doubleRead = llvm::Function::Create(doubleType, llvm::GlobalValue::ExternalLinkage, "double_read", &mdl);
    llvm::Function* charRead = llvm::Function::Create(charType, llvm::GlobalValue::ExternalLinkage, "char_read", &mdl);
    intRead -> setCallingConv(llvm::CallingConv::C);
    doubleRead -> setCallingConv(llvm::CallingConv::C);
    charRead -> setCallingConv(llvm::CallingConv::C);
    ee.addGlobalMapping((llvm::GlobalValue*)intRead, reinterpret_cast<void*>(&intWriteLn));
    ee.addGlobalMapping((llvm::GlobalValue*)doubleRead, reinterpret_cast<void*>(&doubleWriteLn));
    ee.addGlobalMapping((llvm::GlobalValue*)charRead, reinterpret_cast<void*>(&charWriteLn));
    auto* intFunc = new ASTFunction("intRead", intRead, intType, intArgs);
    astContext.addFunction("intRead",intFunc);
    auto* doubleFunc = new ASTFunction("doubleRead", intRead, intType, intArgs);
    astContext.addFunction("doubleRead",doubleFunc);
    auto* charFunc = new ASTFunction("charRead", intRead, intType, intArgs);
    astContext.addFunction("charRead",charFunc);
}
