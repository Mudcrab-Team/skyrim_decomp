// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: StackFrame; size 0x40
#pragma once

#include "BSTSmartPointer_RE__BSScript__IFunction_e1c76098.h"
#include "BSTSmartPointer_RE__BSScript__ObjectTypeInfo_d4d9dc4f.h"
#include "Variable.h"
struct Stack;
struct StackFrame {
    Stack* parent;
    StackFrame* previousFrame;
    BSTSmartPointer_RE__BSScript__IFunction_e1c76098 owningFunction;
    BSTSmartPointer_RE__BSScript__ObjectTypeInfo_d4d9dc4f owningObjectType;
    unsigned int instructionPointer;
    unsigned int pad24;
    Variable self;
    unsigned int size;
    bool instructionsValid;
    unsigned char pad3D;
    unsigned short pad3E;
};
static_assert(sizeof(StackFrame) == 64, "StackFrame layout differs from the PDB");
