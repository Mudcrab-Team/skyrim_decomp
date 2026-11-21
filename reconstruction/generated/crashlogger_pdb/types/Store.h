// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Store; size 0x2a0
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "IMemoryStoreBase.h"
struct BlockHeader;
struct FreeBlock;
struct StoreBlock;
struct Store {
    IMemoryStoreBase _base;
    unsigned char lock_raw[8];
    void* allocBase;
    void* allocEndMin;
    void* allocEnd;
    void* storeEnd;
    BlockHeader* lastBlock;
    FreeBlock* smallFree[66];
    FreeBlock* currentFree;
    FreeBlock* nextMerge;
    StoreBlock* storeBlockMin;
    StoreBlock* nextStoreBlock;
    StoreBlock* freeStoreBlockList;
    unsigned int currentThread;
    unsigned char undefined_274[4];
    unsigned long long allocated;
    unsigned int numAllocatedBlocks;
    unsigned char undefined_284[4];
    unsigned long long free;
    unsigned int numFreeBlocks;
    unsigned int compacted;
    unsigned int batchDeallocateTlsSlot;
    unsigned char undefined_29c[4];
};
static_assert(sizeof(Store) == 672, "Store layout differs from the PDB");
