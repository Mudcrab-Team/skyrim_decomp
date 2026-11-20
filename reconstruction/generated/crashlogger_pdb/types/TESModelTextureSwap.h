// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESModelTextureSwap; size 0x38
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString.h"
struct BSResource__ID;
struct TESModelTextureSwap__VFTable;
struct TESModelTextureSwap {
    TESModelTextureSwap__VFTable* vftable_TESModelTextureSwap_0;
    BSFixedString ModelName_8;
    BSResource__ID* Textures_10;
    void* Addons_18;
    unsigned short NumTextures_20;
    unsigned short NumAddons_22;
    char _pad_24[4];
    void* AlternateTextures_28;
    int NumAlternateTextures_30;
    char _pad_34[4];
};
static_assert(sizeof(TESModelTextureSwap) == 56, "TESModelTextureSwap layout differs from the PDB");
