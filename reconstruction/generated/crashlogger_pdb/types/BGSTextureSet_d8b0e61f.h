// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSTextureSet; size 0x130
// one of 2 different PDB types sharing this name
#pragma once

#include "BSTextureSet.h"
#include "TESBoundObject.h"
struct DecalData;
struct BGSTextureSet_d8b0e61f {
    TESBoundObject _base;
    BSTextureSet _base_BSTextureSet;
    unsigned char textures_raw[128];
    DecalData* decalData;
    unsigned short flags;  // Flag in the PDB is wider than this slot
    unsigned short pad0CA;
    unsigned char textureFileIDs_raw[96];
    unsigned int pad12C;
};
static_assert(sizeof(BGSTextureSet_d8b0e61f) == 304, "BGSTextureSet_d8b0e61f layout differs from the PDB");
