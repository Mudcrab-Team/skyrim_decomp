// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiSourceTexture; size 0x58
// one of 2 different PDB types sharing this name
#pragma once

#include "NiTexture_b3b6b2ac.h"
struct Stream;
struct Texture;
struct NiSourceTexture_cc202fc8 {
    NiTexture_b3b6b2ac _base;
    Stream* resourceStream;
    Texture* rendererTexture;
    unsigned char flags;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(NiSourceTexture_cc202fc8) == 88, "NiSourceTexture_cc202fc8 layout differs from the PDB");
