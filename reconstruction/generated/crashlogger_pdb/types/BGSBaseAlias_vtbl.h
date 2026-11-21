// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSBaseAlias_vtbl; size 0x20
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct BSFixedString_char_83b572b4;
struct TESFile_8388152d;
struct BGSBaseAlias_vtbl {
    void (*_dtor_BGSBaseAlias)(void);
    bool (*Load)(TESFile_8388152d* );
    void (*InitItem)(TESFile_8388152d* );
    BSFixedString_char_83b572b4*(*QType)(void);
};
static_assert(sizeof(BGSBaseAlias_vtbl) == 32, "BGSBaseAlias_vtbl layout differs from the PDB");
