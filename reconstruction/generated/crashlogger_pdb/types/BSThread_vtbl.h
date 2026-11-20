// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSThread_vtbl; size 0x18
#pragma once
struct BSThread_vtbl {
    void (*_dtor_BSThread)(void);
    unsigned int (*ThreadProc)(void);
    void (*Unk_02)(void);
};
static_assert(sizeof(BSThread_vtbl) == 24, "BSThread_vtbl layout differs from the PDB");
