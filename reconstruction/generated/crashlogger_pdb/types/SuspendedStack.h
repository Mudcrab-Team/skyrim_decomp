// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SuspendedStack; size 0x10
#pragma once

#include "BSTSmartPointer_RE__BSScript__Internal__IFuncCallQuery_d58fea44.h"
#include "BSTSmartPointer_RE__BSScript__Stack_209f1f96.h"
struct SuspendedStack {
    BSTSmartPointer_RE__BSScript__Stack_209f1f96 stack;
    BSTSmartPointer_RE__BSScript__Internal__IFuncCallQuery_d58fea44 funcCallQuery;
};
static_assert(sizeof(SuspendedStack) == 16, "SuspendedStack layout differs from the PDB");
