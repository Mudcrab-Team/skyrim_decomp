// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpDebugInfoOnPendingOperationQueues; size 0x20
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct hkArray_hkWorldOperation__BiggestOperation_hkContainerHeapAllocator;
struct hkpDebugInfoOnPendingOperationQueues {
    hkArray_hkWorldOperation__BiggestOperation_hkContainerHeapAllocator* m_pending_0;
    int m_nextPendingOperationIndex_8;
    char _pad_C[4];
    hkpDebugInfoOnPendingOperationQueues* m_nextQueue_10;
    hkpDebugInfoOnPendingOperationQueues* m_prevQueue_18;
};
static_assert(sizeof(hkpDebugInfoOnPendingOperationQueues) == 32, "hkpDebugInfoOnPendingOperationQueues layout differs from the PDB");
