// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSTextureSet; size 0x130
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSTextureSet_221067b1.h"
#include "TESBoundObject_fc790793.h"
struct DecalData_8ca90d9e;
struct BGSTextureSet {
    TESBoundObject_fc790793 _base;
    BSTextureSet_221067b1 _base_BSTextureSet;
    unsigned char textures_raw[128];
    DecalData_8ca90d9e* decalData;
    unsigned short flags;  // Flag in the PDB is wider than this slot
    unsigned short pad0CA;
    unsigned char textureFileIDs_raw[96];
    unsigned int pad12C;
};
static_assert(sizeof(BGSTextureSet) == 304, "BGSTextureSet layout differs from the PDB");
