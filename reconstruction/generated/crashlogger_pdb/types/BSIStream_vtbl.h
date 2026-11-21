// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSIStream_vtbl; size 0x8
#pragma once
struct BSIStream_vtbl {
    void (*_dtor_BSIStream)(void);
};
static_assert(sizeof(BSIStream_vtbl) == 8, "BSIStream_vtbl layout differs from the PDB");
