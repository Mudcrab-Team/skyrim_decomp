// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSPathingSolution; size 0xb0
#pragma once

#include "BSIntrusiveRefCounted.h"
#include "BSTArray_RE__BSPathingNode_a67b1ac9.h"
#include "BSTArray_RE__BSVirtualPathingNode_RE__BSTSmallArrayHeapAllocator_112_39011e48.h"
struct BSPathingSolution {
    BSIntrusiveRefCounted _base;
    unsigned char undefined_4[4];
    BSTArray_RE__BSVirtualPathingNode_RE__BSTSmallArrayHeapAllocator_112_39011e48 virtualPathingNodes;
    int firstLoadedVirtualNodeIndex;
    int lastLoadedVirtualNodeIndex;
    BSTArray_RE__BSPathingNode_a67b1ac9 currentPathingNodes;
    bool bIncompletePath;
    bool bRequestGoalUnused;
    unsigned char undefined_aa[6];
};
static_assert(sizeof(BSPathingSolution) == 176, "BSPathingSolution layout differs from the PDB");
