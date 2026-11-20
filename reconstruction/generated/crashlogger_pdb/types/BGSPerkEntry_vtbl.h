// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSPerkEntry_vtbl; size 0x60
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkpPhantomType.h"
struct BGSPerkEntry_vtbl {
    bool (*CheckConditionFilters)(unsigned int, void* );
    void (*GetFunction)(void);
    void*(*GetFunctionData)(void);
    void (*_dtor_BGSPerkEntry)(void);
    hkpPhantomType (*GetType)(void);
    void (*ClearData)(void);
    void (*InitItem)(char32_t* );
    bool (*Load)(char32_t* );
    void (*SetParent)(char32_t* );
    unsigned short (*GetID)(void);
    void (*ApplyPerkEntry)(char32_t* );
    void (*RemovePerkEntry)(char32_t* );
};
static_assert(sizeof(BGSPerkEntry_vtbl) == 96, "BGSPerkEntry_vtbl layout differs from the PDB");
