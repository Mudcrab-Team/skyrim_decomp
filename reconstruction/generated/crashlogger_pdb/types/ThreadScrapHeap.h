// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ThreadScrapHeap; size 0xa0
#pragma once

#include "ScrapHeap_aea37981.h"
struct ThreadScrapHeap {
    ScrapHeap_aea37981 heap;
    ThreadScrapHeap* next;
    unsigned int owningThread;
    unsigned int pad;
};
static_assert(sizeof(ThreadScrapHeap) == 160, "ThreadScrapHeap layout differs from the PDB");
