// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FunctionMessage; size 0x18
#pragma once

#include "BSTSmartPointer_RE__BSScript__Internal__IFuncCallQuery_d58fea44.h"
#include "BSTSmartPointer_RE__BSScript__Stack_209f1f96.h"
#include "Type_bad13f76.h"
struct FunctionMessage {
    Type_bad13f76 type;
    unsigned int pad04;
    BSTSmartPointer_RE__BSScript__Stack_209f1f96 stack;
    BSTSmartPointer_RE__BSScript__Internal__IFuncCallQuery_d58fea44 funcQuery;
};
static_assert(sizeof(FunctionMessage) == 24, "FunctionMessage layout differs from the PDB");
