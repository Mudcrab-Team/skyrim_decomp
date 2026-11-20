// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ScrapHeap; size 0x90
// one of 2 different PDB types sharing this name
#pragma once

#include "IMemoryStore.h"
struct Block;
struct FreeBlock;
struct FreeTreeNode;
struct ScrapHeap_aea37981 {
    IMemoryStore _base;
    FreeBlock* smallBlocks[6];
    FreeTreeNode* freeList;
    Block* lastBlock;
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
static_assert(sizeof(ScrapHeap_aea37981) == 144, "ScrapHeap_aea37981 layout differs from the PDB");
