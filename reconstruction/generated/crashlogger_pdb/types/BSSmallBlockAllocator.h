// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSSmallBlockAllocator; size 0x1268
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSCriticalSection.h"
#include "IMemoryStore_a344a2ac.h"
struct MegaBlockPage;
struct BSSmallBlockAllocator {
    IMemoryStore_a344a2ac _base;
    unsigned char pools_raw[4608];
    BSCriticalSection lock;
    unsigned int addressSpaceSize;
    unsigned int pad1234;
    unsigned char* allocBase;
    unsigned char* blockPageCommitMin;
    unsigned char* blockPageCommit;
    MegaBlockPage* megaBlockPageList;
    MegaBlockPage* megaBlockCurrAlloc;
    unsigned int totalFreeBlockPages;
    bool allowDecommits;
    unsigned char pad1265;
    unsigned short pad1266;
};
static_assert(sizeof(BSSmallBlockAllocator) == 4712, "BSSmallBlockAllocator layout differs from the PDB");
