// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSOpenCloseForm_vtbl; size 0x20
#pragma once
struct BGSOpenCloseForm_vtbl {
    void (*_dtor_BGSOpenCloseForm)(void);
    void (*HandleOpen)(char32_t* , char32_t* );
    void (*HandleClose)(char32_t* , char32_t* );
    void (*Unk_03)(void);
};
static_assert(sizeof(BGSOpenCloseForm_vtbl) == 32, "BGSOpenCloseForm_vtbl layout differs from the PDB");
