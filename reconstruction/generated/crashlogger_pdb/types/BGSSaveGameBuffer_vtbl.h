// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSSaveGameBuffer_vtbl; size 0x20
// one of 2 different PDB types sharing this name; the fullest
#pragma once
struct BGSSaveGameBuffer_vtbl {
    void (*_dtor_BGSSaveGameBuffer)(void);
    char32_t*(*GetForm)(void);
    char32_t*(*GetReference)(void);
    char32_t*(*GetActor)(void);
};
static_assert(sizeof(BGSSaveGameBuffer_vtbl) == 32, "BGSSaveGameBuffer_vtbl layout differs from the PDB");
