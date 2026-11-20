// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ISavePatcherInterface_vtbl; size 0x10
#pragma once
struct ISavePatcherInterface_vtbl {
    void (*_dtor_ISavePatcherInterface)(void);
    void (*PatchStackFrame)(char32_t* , char32_t* );
};
static_assert(sizeof(ISavePatcherInterface_vtbl) == 16, "ISavePatcherInterface_vtbl layout differs from the PDB");
