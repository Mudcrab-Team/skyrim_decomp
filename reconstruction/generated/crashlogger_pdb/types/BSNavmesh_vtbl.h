// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSNavmesh_vtbl; size 0x10
#pragma once
struct BSNavmesh_vtbl {
    void (*_dtor_BSNavmesh)(void);
    unsigned int (*QNavmeshID)(void);
};
static_assert(sizeof(BSNavmesh_vtbl) == 16, "BSNavmesh_vtbl layout differs from the PDB");
