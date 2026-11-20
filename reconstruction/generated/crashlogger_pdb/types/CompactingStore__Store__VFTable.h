// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CompactingStore__Store__VFTable; size 0x20
#pragma once

struct IMemoryStoreBase_baec62b5;
struct CompactingStore__Store__VFTable {
    unsigned long long*(*dtor_0)(IMemoryStoreBase_baec62b5* , char);
    int (*Size_8)(void);
    int (*GetMemoryStats_10)(void);
    int (*ContainsBlockImpl_18)(void);
};
static_assert(sizeof(CompactingStore__Store__VFTable) == 32, "CompactingStore__Store__VFTable layout differs from the PDB");
