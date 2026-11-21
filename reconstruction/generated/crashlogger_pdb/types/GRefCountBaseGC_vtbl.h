// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GRefCountBaseGC_vtbl; size 0x18
#pragma once
struct GRefCountBaseGC_vtbl {
    int (*Unk_00)(void* );
    void (*Unk_01)(void);
    void (*_dtor_GRefCountBaseGC)(void);
};
static_assert(sizeof(GRefCountBaseGC_vtbl) == 24, "GRefCountBaseGC_vtbl layout differs from the PDB");
