// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraGuardedRefData; size 0x28
#pragma once

#include "BSExtraData_4ca6af76.h"
#include "BSTArray_RE__ExtraGuardedRefData__GuardInfo_bd5ce016.h"
struct ExtraGuardedRefData {
    BSExtraData_4ca6af76 _base;
    BSTArray_RE__ExtraGuardedRefData__GuardInfo_bd5ce016 guards;
};
static_assert(sizeof(ExtraGuardedRefData) == 40, "ExtraGuardedRefData layout differs from the PDB");
