// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSArtObject; size 0x70
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString.h"
#include "TESBoundObject__Data.h"
#include "TESFileContainer_70f0bdf4.h"
struct BGSArtObject__VFTable;
struct BSResource__ID;
struct TESModelTextureSwap__VFTable;
struct BGSArtObject {
    BGSArtObject__VFTable* vftable_BGSArtObject_0;
    TESFileContainer_70f0bdf4 FormSourceFiles_8;
    unsigned int FormFlags_10;
    unsigned int FormId_14;
    unsigned short FormGameFlags_18;
    unsigned char FormType_1A;
    char _pad_1B[5];
    TESBoundObject__Data BoundData_20;
    char _pad_2C[4];
    TESModelTextureSwap__VFTable* vftable_TESModelTextureSwap_30;
    BSFixedString ModelName_38;
    BSResource__ID* Textures_40;
    void* Addons_48;
    unsigned short NumTextures_50;
    unsigned short NumAddons_52;
    char _pad_54[4];
    void* AlternateTextures_58;
    int NumAlternateTextures_60;
    char _pad_64[4];
    unsigned char data_raw[4];
    unsigned int pad6C;
};
static_assert(sizeof(BGSArtObject) == 112, "BGSArtObject layout differs from the PDB");
