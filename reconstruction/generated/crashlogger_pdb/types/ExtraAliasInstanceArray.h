// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraAliasInstanceArray; size 0x30
#pragma once

#include "BSExtraData_4ca6af76.h"
#include "BSReadWriteLock.h"
#include "BSTArray_RE__BGSRefAliasInstanceData_c79843a3.h"
struct ExtraAliasInstanceArray {
    BSExtraData_4ca6af76 _base;
    BSTArray_RE__BGSRefAliasInstanceData_c79843a3 aliases;
    BSReadWriteLock lock;
};
static_assert(sizeof(ExtraAliasInstanceArray) == 48, "ExtraAliasInstanceArray layout differs from the PDB");
