// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IPathBuilder_vtbl; size 0x10
#pragma once
struct IPathBuilder_vtbl {
    void (*_dtor_IPathBuilder)(void);
    void (*Build)(void);
};
static_assert(sizeof(IPathBuilder_vtbl) == 16, "IPathBuilder_vtbl layout differs from the PDB");
