// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IMemoryStoreBase_vtbl; size 0x20
#pragma once
struct IMemoryStoreBase_vtbl {
    void (*_dtor_IMemoryStoreBase)(void);
    unsigned long long (*Size)(void* );
    void (*GetMemoryStats)(char32_t* );
    bool (*ContainsBlockImpl)(void* );
};
static_assert(sizeof(IMemoryStoreBase_vtbl) == 32, "IMemoryStoreBase_vtbl layout differs from the PDB");
