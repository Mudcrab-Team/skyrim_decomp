// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CodeTasklet; size 0x50
#pragma once

#include "IFuncCallQuery.h"
#include "ResumeReason.h"
struct ErrorLogger;
struct Stack;
struct StackFrame;
struct VirtualMachine;
struct CodeTasklet {
    IFuncCallQuery _base;
    Stack* stack;
    VirtualMachine* vm;
    ErrorLogger* errorLogger;
    ResumeReason resumeReason;
    unsigned int pad2C;
    StackFrame* topFrame;
    unsigned int frameMemoryPage;
    unsigned char jumpBitCount;
    unsigned char localVarBitCount;
    unsigned char memberVarBitCount;
    unsigned char pad3F;
    unsigned int instructionDataBitCount;
    unsigned int pad44;
    void* instructionDataStart;
};
static_assert(sizeof(CodeTasklet) == 80, "CodeTasklet layout differs from the PDB");
