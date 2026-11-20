// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSBaseAlias_vtbl; size 0x20
// one of 2 different PDB types sharing this name
#pragma once
struct BGSBaseAlias_vtbl_d9982b4c {
    void (*_dtor_BGSBaseAlias)(void);
    bool (*Load)(char32_t* );
    void (*InitItem)(char32_t* );
    char32_t*(*QType)(void);
};
static_assert(sizeof(BGSBaseAlias_vtbl_d9982b4c) == 32, "BGSBaseAlias_vtbl_d9982b4c layout differs from the PDB");
