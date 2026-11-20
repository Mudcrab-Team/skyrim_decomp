// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSMaterialObject_vtbl; size 0x10
#pragma once
struct BSMaterialObject_vtbl {
    void (*_dtor_BSMaterialObject)(void);
    void (*EnsureLoaded)(void);
};
static_assert(sizeof(BSMaterialObject_vtbl) == 16, "BSMaterialObject_vtbl layout differs from the PDB");
