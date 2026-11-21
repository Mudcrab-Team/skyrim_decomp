// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTasklet_vtbl; size 0x8
#pragma once
struct BSTasklet_vtbl {
    void (*_dtor_BSTasklet)(void);
};
static_assert(sizeof(BSTasklet_vtbl) == 8, "BSTasklet_vtbl layout differs from the PDB");
