// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESModelTextureSwap; size 0x38
// one of 2 different PDB types sharing this name
#pragma once

#include "TESModel_c52655e4.h"
struct AlternateTexture;
struct TESModelTextureSwap_014aa4ed {
    TESModel_c52655e4 _base;
    AlternateTexture* alternateTextures;
    unsigned int numAlternateTextures;
    unsigned int pad34;
};
static_assert(sizeof(TESModelTextureSwap_014aa4ed) == 56, "TESModelTextureSwap_014aa4ed layout differs from the PDB");
