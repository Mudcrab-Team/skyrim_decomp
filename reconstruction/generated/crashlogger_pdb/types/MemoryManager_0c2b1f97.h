// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MemoryManager; size 0x480
// one of 2 different PDB types sharing this name
#pragma once

struct BSSmallBlockAllocator;
struct CompactingStore__Store;
struct IMemoryHeap;
struct MemoryManager__ThreadScrapHeap;
struct MemoryManager_0c2b1f97 {
    bool Initialized_0;
    char _pad_1;
    unsigned short NumHeaps_2;
    unsigned short NumPhysicalHeaps_4;
    char _pad_6[2];
    IMemoryHeap** Heaps_8;
    bool AllowOtherContextAllocs_10;
    unsigned char _pad_0[7];
    IMemoryHeap* HeapsByContext_18[127];
    MemoryManager__ThreadScrapHeap* ThreadHeap_410;
    IMemoryHeap** PhysicalHeaps_418;
    IMemoryHeap* BigAllocHeap_420;
    IMemoryHeap* EmergencyHeap_428;
    BSSmallBlockAllocator* SmallBlockAllocator_430;
    CompactingStore__Store* CompactStore_438;
    IMemoryHeap* ExternalHavokAllocator_440;
    bool SpecialHeaps_448;
    bool AllowPoolUse_449;
    char _pad_44A[2];
    unsigned int SysAllocBytes_44C;
    unsigned int MallocBytes_450;
    unsigned int AlignmentForPools_454;
    unsigned int MainThreadMemoryProblemPassSignal_458;
    char _pad_45C[4];
    unsigned long long FailedAllocationSize_460;
    unsigned int NumMemoryProblemPassesRun_468;
    char _pad_46C[4];
    unsigned long long TimeOfLastMemoryProblemPass_470;
    IMemoryHeap* DefaultHeap_478;
};
static_assert(sizeof(MemoryManager_0c2b1f97) == 1152, "MemoryManager_0c2b1f97 layout differs from the PDB");
