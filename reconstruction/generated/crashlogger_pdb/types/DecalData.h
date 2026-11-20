// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DecalData; size 0x24
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "Color.h"
struct DecalData {
    float DecalMinWidth_0;
    float DecalMaxWidth_4;
    float DecalMinHeight_8;
    float DecalMaxHeight_C;
    float Depth_10;
    float Shininess_14;
    float ParallaxScale_18;
    char ParallaxPasses_1C;
    unsigned char Flags_1D;
    char _pad_1E[2];
    Color DecalColor_20;
};
static_assert(sizeof(DecalData) == 36, "DecalData layout differs from the PDB");
