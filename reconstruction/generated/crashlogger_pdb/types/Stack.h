// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Stack; size 0xa0
#pragma once

#include "BSIntrusiveRefCounted.h"
#include "BSTArray_RE__BSScript__Stack__MemoryPageData_RE__BSTSmallArrayHeapAllocator_48_3cd73bb3.h"
#include "BSTSmartPointer_RE__BSScript__IStackCallbackFunctor_9ddcac52.h"
#include "BSTSmartPointer_RE__BSScript__Internal__CodeTasklet_e8ad4715.h"
#include "BSTSmartPointer_RE__BSScript__Stack_209f1f96.h"
#include "FreezeState.h"
#include "StackType.h"
#include "State_675e5871.h"
#include "Variable.h"
struct IMemoryPagePolicy;
struct IProfilePolicy;
struct StackFrame;
struct Stack {
    BSIntrusiveRefCounted _base;
    unsigned int pad04;
    IMemoryPagePolicy* policy;
    IProfilePolicy* profilePolicy;
    BSTArray_RE__BSScript__Stack__MemoryPageData_RE__BSTSmallArrayHeapAllocator_48_3cd73bb3 pages;
    unsigned int frames;
    unsigned int pad5C;
    StackFrame* top;
    State_675e5871 state;
    FreezeState freezeState;
    Variable returnValue;
    unsigned int stackID;
    StackType stackType;
    BSTSmartPointer_RE__BSScript__Internal__CodeTasklet_e8ad4715 owningTasklet;
    BSTSmartPointer_RE__BSScript__IStackCallbackFunctor_9ddcac52 callback;
    BSTSmartPointer_RE__BSScript__Stack_209f1f96 nextStack;
};
static_assert(sizeof(Stack) == 160, "Stack layout differs from the PDB");
