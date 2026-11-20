// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ScrapHeap; size 0x90
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "IMemoryStore_a344a2ac.h"
struct Block_90f38ad6;
struct FreeBlock_4f45b8f1;
struct FreeTreeNode_e6a612f2;
struct ScrapHeap {
    IMemoryStore_a344a2ac _base;
    FreeBlock_4f45b8f1* smallBlocks[6];
    FreeTreeNode_e6a612f2* freeList;
    Block_90f38ad6* lastBlock;
    void* baseAddress;
    void* endAddress;
    void* commitEnd;
    unsigned long long reserveSize;
    unsigned long long minCommit;
    unsigned long long totalAllocated;
    unsigned int keepPagesRequest;
    unsigned int totalFreeBlocks;
    unsigned int freeSmallBlocks;
    unsigned int totalAllocatedBlocks;
    unsigned int pmpBarrier;
    unsigned char undefined_8c[4];
};
static_assert(sizeof(ScrapHeap) == 144, "ScrapHeap layout differs from the PDB");
