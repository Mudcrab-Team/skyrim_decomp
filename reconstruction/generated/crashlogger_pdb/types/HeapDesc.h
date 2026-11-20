// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: HeapDesc; size 0x40
#pragma once

#include "GHeapID.h"
#include "HeapFlags.h"
struct HeapDesc {
    HeapFlags flags;
    unsigned int pad04;
    unsigned long long minAlign;
    unsigned long long granularity;
    unsigned long long reserve;
    unsigned long long threshold;
    unsigned long long limit;
    GHeapID heapID;
    unsigned char _pad_0[4];
    unsigned long long arena;
};
static_assert(sizeof(HeapDesc) == 64, "HeapDesc layout differs from the PDB");
