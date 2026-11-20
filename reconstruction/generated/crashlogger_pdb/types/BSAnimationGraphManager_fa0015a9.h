// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSAnimationGraphManager; size 0xb0
// one of 2 different PDB types sharing this name
#pragma once

#include "BSAnimationGraphVariableCache.h"
#include "BSIntrusiveRefCounted_8d4cb673.h"
#include "BSSpinLock.h"
#include "BSTArray_RE__BSTSmartPointer_RE__BSAnimationGraphChannel_de4ee8e0_85ffed51.h"
#include "BSTArray_RE__BSTSmartPointer_RE__BSAnimationGraphManager_a3451539_9ef2b48f.h"
#include "BSTArray_RE__BSTSmartPointer_RE__BShkbAnimationGraph_RE__BSTSmallArrayHeapAllocator_8_0_99606e19.h"
#include "BSTEventSink_RE__BSAnimationGraphEvent_bc0d6f4d.h"
struct BSAnimationGraphManager_fa0015a9 {
    BSTEventSink_RE__BSAnimationGraphEvent_bc0d6f4d _base;
    BSIntrusiveRefCounted_8d4cb673 _base_BSIntrusiveRefCounted;
    unsigned int pad0C;
    BSTArray_RE__BSTSmartPointer_RE__BSAnimationGraphChannel_de4ee8e0_85ffed51 boundChannels;
    BSTArray_RE__BSTSmartPointer_RE__BSAnimationGraphChannel_de4ee8e0_85ffed51 bumpedChannels;
    BSTArray_RE__BSTSmartPointer_RE__BShkbAnimationGraph_RE__BSTSmallArrayHeapAllocator_8_0_99606e19 graphs;
    BSTArray_RE__BSTSmartPointer_RE__BSAnimationGraphManager_a3451539_9ef2b48f subManagers;
    BSAnimationGraphVariableCache variableCache;
    BSSpinLock updateLock;
    BSSpinLock dependentManagerLock;
    unsigned int activeGraph;
    unsigned int generateDepth;
};
static_assert(sizeof(BSAnimationGraphManager_fa0015a9) == 176, "BSAnimationGraphManager_fa0015a9 layout differs from the PDB");
