// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSArtObject; size 0x70
// one of 2 different PDB types sharing this name
#pragma once

#include "TESBoundObject_fc790793.h"
#include "TESModelTextureSwap_014aa4ed.h"
struct BGSArtObject_14762d66 {
    TESBoundObject_fc790793 _base;
    TESModelTextureSwap_014aa4ed _base_TESModelTextureSwap;
    unsigned char data_raw[4];
    unsigned int pad6C;
};
static_assert(sizeof(BGSArtObject_14762d66) == 112, "BGSArtObject_14762d66 layout differs from the PDB");
