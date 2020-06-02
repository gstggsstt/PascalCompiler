//
// Created by buttshark on 6/2/20.
//

#include "SystemCall.h"
void writeLn() {
    std::cout << std::endl;
}
void intWrite(int64_t a) {
    std::cout << a;
}
void doubleWrite(double_t a) {
    std::cout << a;
}
void charWrite(int8_t a) {
    std::cout << (char)a;
}

void addSystemFuncWrite(llvm::Module &mdl, llvm::ExecutionEngine &ee, llvm::IRBuilder<> &bdr,ASTContext &astContext) {
    std::vector<llvm::Type*> intArgs;
    std::vector<llvm::Type*> doubleArgs;
    std::vector<llvm::Type*> charArgs;
    std::vector<llvm::Type*> voidArgs;
    intArgs.push_back(bdr.getInt64Ty());
    doubleArgs.push_back(bdr.getDoubleTy());
    charArgs.push_back(bdr.getInt8Ty());
    llvm::FunctionType *intType = llvm::FunctionType::get(bdr.getVoidTy(), intArgs, false);
    llvm::FunctionType *doubleType = llvm::FunctionType::get(bdr.getVoidTy(), doubleArgs, false);
    llvm::FunctionType *charType = llvm::FunctionType::get(bdr.getVoidTy(), charArgs, false);
    llvm::FunctionType *lnType = llvm::FunctionType::get(bdr.getVoidTy(), voidArgs, false);
    llvm::Function* intPrint = llvm::Function::Create(intType,llvm::GlobalValue::ExternalLinkage,"int_print",&mdl);
    llvm::Function* doublePrint = llvm::Function::Create(doubleType,llvm::GlobalValue::ExternalLinkage,"double_print",&mdl);
    llvm::Function* charPrint = llvm::Function::Create(charType,llvm::GlobalValue::ExternalLinkage,"char_print",&mdl);
    llvm::Function* endlPrint = llvm::Function::Create(lnType,llvm::GlobalValue::ExternalLinkage,"endl_print",&mdl);
    intPrint -> setCallingConv(llvm::CallingConv::C);
    doublePrint -> setCallingConv(llvm::CallingConv::C);
    charPrint -> setCallingConv(llvm::CallingConv::C);
    endlPrint -> setCallingConv(llvm::CallingConv::C);
    ee.addGlobalMapping((llvm::GlobalValue*)intPrint, (void*)&intWrite);
    ee.addGlobalMapping((llvm::GlobalValue*)doublePrint, (void*)&doubleWrite);
    ee.addGlobalMapping((llvm::GlobalValue*)charPrint, (void*)&charWrite);
    ee.addGlobalMapping((llvm::GlobalValue*)endlPrint, (void*)&writeLn);
    auto* intFunc = new ASTFunction("intWrite",intPrint, intType,intArgs);
    astContext.addFunction("intWrite",intFunc);
    auto* doubleFunc = new ASTFunction("doubleWrite",doublePrint, doubleType,doubleArgs);
    astContext.addFunction("doubleWrite",doubleFunc);
    auto* charFunc = new ASTFunction("charWrite",charPrint, charType,charArgs);
    astContext.addFunction("charWrite",charFunc);
    auto* endlFunc = new ASTFunction("writeLn",endlPrint, lnType ,voidArgs);
    astContext.addFunction("writeLn", endlFunc);
}

int64_t getInt()
{
    int64_t a;
    std::cin >> a;
    return a;
}

double_t getDouble()
{
    double_t a;
    std::cin >> a;
    return a;
}

int8_t getChar()
{
    int8_t a;
    std::cin >> a;
    return a;
}

void addSystemFuncRead(llvm::Module &mdl, llvm::ExecutionEngine &ee, llvm::IRBuilder<> &bdr,ASTContext &astContext) {
    std::vector<llvm::Type*> intArgs;
    std::vector<llvm::Type*> doubleArgs;
    std::vector<llvm::Type*> charArgs;
    intArgs.push_back(bdr.getVoidTy());
    doubleArgs.push_back(bdr.getVoidTy());
    charArgs.push_back(bdr.getVoidTy());
    llvm::FunctionType *intType = llvm::FunctionType::get(bdr.getInt64Ty(), intArgs, false);
    llvm::FunctionType *doubleType = llvm::FunctionType::get(bdr.getDoubleTy(), doubleArgs, false);
    llvm::FunctionType *charType = llvm::FunctionType::get(bdr.getInt8Ty(), charArgs, false);
    llvm::Function* intRead = llvm::Function::Create(intType, llvm::GlobalValue::ExternalLinkage, "int_read", &mdl);
    llvm::Function* doubleRead = llvm::Function::Create(doubleType, llvm::GlobalValue::ExternalLinkage, "double_read", &mdl);
    llvm::Function* charRead = llvm::Function::Create(charType, llvm::GlobalValue::ExternalLinkage, "char_read", &mdl);
    intRead -> setCallingConv(llvm::CallingConv::C);
    doubleRead -> setCallingConv(llvm::CallingConv::C);
    charRead -> setCallingConv(llvm::CallingConv::C);
    ee.addGlobalMapping((llvm::GlobalValue*)intRead, reinterpret_cast<void*>(&getInt));
    ee.addGlobalMapping((llvm::GlobalValue*)doubleRead, reinterpret_cast<void*>(&getDouble));
    ee.addGlobalMapping((llvm::GlobalValue*)charRead, reinterpret_cast<void*>(&getChar));
    auto* intFunc = new ASTFunction("intRead", intRead, intType, intArgs);
    astContext.addFunction("intRead",intFunc);
    auto* doubleFunc = new ASTFunction("doubleRead", intRead, intType, intArgs);
    astContext.addFunction("doubleRead",doubleFunc);
    auto* charFunc = new ASTFunction("charRead", intRead, intType, intArgs);
    astContext.addFunction("charRead",charFunc);
}
