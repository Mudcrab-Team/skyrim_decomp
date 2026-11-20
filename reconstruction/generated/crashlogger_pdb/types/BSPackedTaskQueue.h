// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSPackedTaskQueue; size 0x40
#pragma once

#include "BSTCommonScrapHeapMessageQueue_RE__BSPackedTask_cb7d747b.h"
#include "Semaphore.h"
struct BSPackedTaskQueue {
    BSTCommonScrapHeapMessageQueue_RE__BSPackedTask_cb7d747b queue;
    Semaphore semaphore;
    unsigned char unpackFunc_raw[8];
};
static_assert(sizeof(BSPackedTaskQueue) == 64, "BSPackedTaskQueue layout differs from the PDB");
