// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DIRECTIONAL_DATA; size 0x38
// one of 2 different PDB types sharing this name
#pragma once

#include "Flag_d5bcd2af.h"
#include "NiColor.h"
#include "NiPoint3_a7124070.h"
struct DIRECTIONAL_DATA_71dc29a6 {
    float falloffScale;
    float falloffBias;
    float noiseUVScale;
    float materialUVScale;
    NiPoint3_a7124070 ProjectionDir;
    float normalDampener;
    NiColor singlePassColor;
    int singlePass;
    Flag_d5bcd2af flags;
    unsigned int unk2C;
};
static_assert(sizeof(DIRECTIONAL_DATA_71dc29a6) == 56, "DIRECTIONAL_DATA_71dc29a6 layout differs from the PDB");
