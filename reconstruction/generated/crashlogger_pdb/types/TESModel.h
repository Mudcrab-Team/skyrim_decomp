// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESModel; size 0x28
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString.h"
struct BSResource__ID;
struct TESModel__VFTable;
struct TESModel {
    TESModel__VFTable* vftable_TESModel_0;
    BSFixedString ModelName_8;
    BSResource__ID* Textures_10;
    void* Addons_18;
    unsigned short NumTextures_20;
    unsigned short NumAddons_22;
    char _pad_24[4];
};
static_assert(sizeof(TESModel) == 40, "TESModel layout differs from the PDB");
