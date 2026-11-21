// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSQueuedResourceCollectionBase; size 0x88
#pragma once

#include "BSTArray_RE__QueuedResourceEntry_RE__BSTSmallArrayHeapAllocator_32_7e23f934.h"
#include "PostFlushNotify.h"
#include "QueuedFile_8dc5a4cb.h"
struct BSQueuedResourceCollectionBase {
    QueuedFile_8dc5a4cb _base;
    PostFlushNotify _base_PostFlushNotify;
    unsigned int pendingCount;
    bool needNotifyFlag;
    bool unk55;
    unsigned short pad56;
    BSTArray_RE__QueuedResourceEntry_RE__BSTSmallArrayHeapAllocator_32_7e23f934 queue;
};
static_assert(sizeof(BSQueuedResourceCollectionBase) == 136, "BSQueuedResourceCollectionBase layout differs from the PDB");
