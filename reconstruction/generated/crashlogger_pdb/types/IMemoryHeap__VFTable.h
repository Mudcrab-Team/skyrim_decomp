// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IMemoryHeap__VFTable; size 0x78
#pragma once

struct IMemoryStoreBase_baec62b5;
struct IMemoryHeap__VFTable {
    unsigned long long*(*dtor_0)(IMemoryStoreBase_baec62b5* , char);
    int (*Size_8)(void);
    int (*GetMemoryStats_10)(void);
    int (*ContainsBlockImpl_18)(void);
    int (*AllocateAlignImpl_20)(void);
    int (*DeallocateAlignImpl_28)(void);
    long long (*TryAllocateImpl_30)(void);
    int (*GetName_38)(void);
    int (*Allocate_40)(void);
    int (*Deallocate_48)(void);
    int (*PointerInHeap_50)(void);
    int (*TotalSize_58)(void);
    int (*GetHeapStats_60)(void);
    int (*ShouldTrySmallBlockPools_68)(void);
    int (*GetPageSize_70)(void);
};
static_assert(sizeof(IMemoryHeap__VFTable) == 120, "IMemoryHeap__VFTable layout differs from the PDB");
