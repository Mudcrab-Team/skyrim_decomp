// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSAnimationGraphVariableCache; size 0x28
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__AnimVariableCacheInfo_4c90f704.h"
#include "BSTSmartPointer_RE__BShkbAnimationGraph_cefde0c0.h"
struct BSAnimationGraphVariableCache {
    BSTArray_RE__AnimVariableCacheInfo_4c90f704 variableCache;
    BSSpinLock updateLock;
    BSTSmartPointer_RE__BShkbAnimationGraph_cefde0c0 animationGraph;
};
static_assert(sizeof(BSAnimationGraphVariableCache) == 40, "BSAnimationGraphVariableCache layout differs from the PDB");
