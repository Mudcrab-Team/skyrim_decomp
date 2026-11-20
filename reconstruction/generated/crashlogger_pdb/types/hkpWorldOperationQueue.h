// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpWorldOperationQueue; size 0x38
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkArray_hkWorldOperation__BiggestOperation_hkContainerHeapAllocator.h"
#include "hkArray_hkpBodyOperationEntry_hkContainerHeapAllocator.h"
struct hkpWorld_938ebb10;
struct hkpWorldOperationQueue {
    hkArray_hkWorldOperation__BiggestOperation_hkContainerHeapAllocator m_pending_0;
    hkpWorld_938ebb10* m_world_10;
    hkArray_hkWorldOperation__BiggestOperation_hkContainerHeapAllocator m_islandMerges_18;
    hkArray_hkpBodyOperationEntry_hkContainerHeapAllocator m_pendingBodyOperations_28;
};
static_assert(sizeof(hkpWorldOperationQueue) == 56, "hkpWorldOperationQueue layout differs from the PDB");
