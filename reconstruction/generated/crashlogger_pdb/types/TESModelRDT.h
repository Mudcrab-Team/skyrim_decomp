// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESModelRDT; size 0x28
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString.h"
struct BSResource__ID;
struct TESModelRDT__VFTable;
struct TESModelRDT {
    TESModelRDT__VFTable* vftable_TESModelRDT_0;
    BSFixedString ModelName_8;
    BSResource__ID* Textures_10;
    void* Addons_18;
    unsigned short NumTextures_20;
    unsigned short NumAddons_22;
    char _pad_24[4];
};
static_assert(sizeof(TESModelRDT) == 40, "TESModelRDT layout differs from the PDB");
