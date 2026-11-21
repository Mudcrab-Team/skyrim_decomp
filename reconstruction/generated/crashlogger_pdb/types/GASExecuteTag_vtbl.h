// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GASExecuteTag_vtbl; size 0x40
#pragma once
struct GASExecuteTag_vtbl {
    void (*_dtor_GASExecuteTag)(void);
    void (*Execute1)(char32_t* );
    void (*Execute2)(char32_t* , int);
    void (*Unk_03)(void);
    void (*Unk_04)(void);
    void (*Unk_05)(void);
    void (*Unk_06)(void);
    void (*Unk_07)(void);
};
static_assert(sizeof(GASExecuteTag_vtbl) == 64, "GASExecuteTag_vtbl layout differs from the PDB");
