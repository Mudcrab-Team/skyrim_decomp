// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkKdTree; size 0x50
#pragma once

#include "hkAabb.h"
#include "hkArray_hkKdTreeNode_hkContainerHeapAllocator.h"
#include "hkArray_hkKdTreeProjectedEntry_hkContainerHeapAllocator.h"
struct hkKdTree {
    hkArray_hkKdTreeNode_hkContainerHeapAllocator m_nodes_0;
    int m_maxDepth_10;
    int m_numPrimitives_14;
    int m_numRegularNodes_18;
    int m_numReservedEmptyNodes_1C;
    hkArray_hkKdTreeProjectedEntry_hkContainerHeapAllocator m_projectedEntries_20;
    hkAabb m_aabb_30;
};
static_assert(sizeof(hkKdTree) == 80, "hkKdTree layout differs from the PDB");
