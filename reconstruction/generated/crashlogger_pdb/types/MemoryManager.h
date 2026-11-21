// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MemoryManager; size 0x480
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct BSSmallBlockAllocator_fc85161d;
struct IMemoryHeap_61590de0;
struct Store;
struct ThreadScrapHeap;
struct MemoryManager {
    bool initialized;
    unsigned char undefined_1[1];
    unsigned short numHeaps;
    unsigned short numPhysicalHeaps;
    unsigned char undefined_6[2];
    IMemoryHeap_61590de0** heaps;
    bool* allowOtherContextAllocs;
    IMemoryHeap_61590de0* heapsByContext[127];
    ThreadScrapHeap* threadScrapHeap;
    IMemoryHeap_61590de0** physicalHeaps;
    IMemoryHeap_61590de0* bigAllocHeap;
    IMemoryHeap_61590de0* emergencyHeap;
    BSSmallBlockAllocator_fc85161d* smallBlockAllocator;
    Store* compactingStore;
    IMemoryHeap_61590de0* externalHavokAllocator;
    bool specialHeaps;
    bool allowPoolUse;
    unsigned char undefined_44a[2];
    unsigned int sysAllocBytes;
    unsigned int mallocBytes;
    unsigned int alignmentForPools;
    unsigned int mainThreadMemoryProblemPassSignal;
    unsigned char undefined_45c[4];
    unsigned long long failedAllocationSize;
    unsigned int numMemoryProblemPassesRun;
    unsigned char undefined_46c[4];
    unsigned long long timeOfLastMemoryProblemPass;
    IMemoryHeap_61590de0* defaultHeap;
};
static_assert(sizeof(MemoryManager) == 1152, "MemoryManager layout differs from the PDB");
