// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSAnimationGraphVariableCache; size 0x20
// one of 2 different PDB types sharing this name
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__AnimVariableCacheInfo_4c90f704_d4eb97cd.h"
struct BSAnimationGraphVariableCache_b779e321 {
    BSTArray_RE__AnimVariableCacheInfo_4c90f704_d4eb97cd variableCache;
    BSSpinLock updateLock;
};
static_assert(sizeof(BSAnimationGraphVariableCache_b779e321) == 32, "BSAnimationGraphVariableCache_b779e321 layout differs from the PDB");
