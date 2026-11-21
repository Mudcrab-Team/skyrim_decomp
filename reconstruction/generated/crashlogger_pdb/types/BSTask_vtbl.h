// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTask_vtbl; size 0x28
#pragma once
struct BSTask_vtbl {
    void (*_dtor_BSTask)(void);
    void (*Unk_01)(void);
    void (*Unk_02)(void);
    void (*Unk_03)(void);
    void (*Unk_04)(void);
};
static_assert(sizeof(BSTask_vtbl) == 40, "BSTask_vtbl layout differs from the PDB");
