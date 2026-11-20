// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSAnimationGraphManager; size 0xb8
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSAnimationGraphVariableCache_b779e321.h"
#include "BSIntrusiveRefCounted.h"
#include "BSTArray_RE__BSTSmartPointer_RE__BSAnimationGraphChannel_de4ee8e0.h"
#include "BSTArray_RE__BSTSmartPointer_RE__BSAnimationGraphManager_a3451539.h"
#include "BSTArray_RE__BSTSmartPointer_RE__BShkbAnimationGraph_RE__BSTSmallArrayHeapAllocator_8_0f1258e5.h"
#include "BSTEventSink_RE__BSAnimationGraphEvent_bc0d6f4d.h"
struct BSAnimationGraphManager {
    BSTEventSink_RE__BSAnimationGraphEvent_bc0d6f4d _base;
    BSIntrusiveRefCounted _base_BSIntrusiveRefCounted;
    unsigned int pad0C;
    BSTArray_RE__BSTSmartPointer_RE__BSAnimationGraphChannel_de4ee8e0 boundChannels;
    BSTArray_RE__BSTSmartPointer_RE__BSAnimationGraphChannel_de4ee8e0 bumpedChannels;
    BSTArray_RE__BSTSmartPointer_RE__BShkbAnimationGraph_RE__BSTSmallArrayHeapAllocator_8_0f1258e5 graphs;
    BSTArray_RE__BSTSmartPointer_RE__BSAnimationGraphManager_a3451539 subManagers;
    BSAnimationGraphVariableCache_b779e321 variableCache;
    unsigned char undefined_90[40];
};
static_assert(sizeof(BSAnimationGraphManager) == 184, "BSAnimationGraphManager layout differs from the PDB");
