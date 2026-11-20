// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: AbstractHeap; size 0x2a8
#pragma once

#include "BSCriticalSection.h"
#include "IMemoryHeap_61590de0.h"
struct HeapBlock;
struct HeapBlockFreeHead;
struct AbstractHeap {
    IMemoryHeap_61590de0 _base;
    BSCriticalSection criticalSection;
    unsigned char* name;
    unsigned long long minFreeBlockSize;
    unsigned int pageSize;
    unsigned int pageSizeFlag;
    unsigned long long memHeapSize;
    unsigned long long initialSize;
    unsigned long long currentSize;
    unsigned long long wastedMemory;
    unsigned long long memAllocated;
    unsigned long long memAllocatedHigh;
    unsigned long long blockMemAllocated;
    unsigned char* memHeap;
    int numBlocks;
    unsigned int pad08C;
    HeapBlock* blockHead;
    HeapBlock* blockTail;
    int numFreeBlocks;
    bool allowDecommits;
    bool supportsSwapping;
    unsigned short pad0A0;
    HeapBlock* smallFreeLists[32];
    HeapBlockFreeHead* largeFreeTrees[32];
};
static_assert(sizeof(AbstractHeap) == 680, "AbstractHeap layout differs from the PDB");
