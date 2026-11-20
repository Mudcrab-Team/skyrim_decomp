// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSLoadGameBuffer_vtbl; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once
struct BGSLoadGameBuffer_vtbl {
    void (*_dtor_BGSLoadGameBuffer)(void);
    unsigned char (*GetVersion)(void);
};
static_assert(sizeof(BGSLoadGameBuffer_vtbl) == 16, "BGSLoadGameBuffer_vtbl layout differs from the PDB");
