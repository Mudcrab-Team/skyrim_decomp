// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSPerkEntry_vtbl; size 0x60
// one of 2 different PDB types sharing this name
#pragma once

#include "FunctorType.h"
struct Actor_b2630b95;
struct BGSPerk_dfc65d7f;
struct ENTRY_POINT;
struct TESFile_8388152d;
struct BGSPerkEntry_vtbl_98fdb43a {
    bool (*CheckConditionFilters)(unsigned int, void* );
    ENTRY_POINT (*GetFunction)(void);
    void*(*GetFunctionData)(void);
    void (*_dtor_BGSPerkEntry)(void);
    FunctorType (*GetType)(void);
    void (*ClearData)(void);
    void (*InitItem)(TESFile_8388152d* );
    bool (*Load)(TESFile_8388152d* );
    void (*SetParent)(BGSPerk_dfc65d7f* );
    unsigned short (*GetID)(void);
    void (*ApplyPerkEntry)(Actor_b2630b95* );
    void (*RemovePerkEntry)(Actor_b2630b95* );
};
static_assert(sizeof(BGSPerkEntry_vtbl_98fdb43a) == 96, "BGSPerkEntry_vtbl_98fdb43a layout differs from the PDB");
