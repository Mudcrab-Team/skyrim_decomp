// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IMemoryStore__VFTable; size 0x38
#pragma once

struct IMemoryStoreBase_baec62b5;
struct IMemoryStore__VFTable {
    unsigned long long*(*dtor_0)(IMemoryStoreBase_baec62b5* , char);
    int (*Size_8)(void);
    int (*GetMemoryStats_10)(void);
    int (*ContainsBlockImpl_18)(void);
    int (*AllocateAlignImpl_20)(void);
    int (*DeallocateAlignImpl_28)(void);
    long long (*TryAllocateImpl_30)(void);
};
static_assert(sizeof(IMemoryStore__VFTable) == 56, "IMemoryStore__VFTable layout differs from the PDB");
