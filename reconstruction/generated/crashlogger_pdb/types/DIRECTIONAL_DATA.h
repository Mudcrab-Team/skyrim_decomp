// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DIRECTIONAL_DATA; size 0x38
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "Flag_a4a94b8a.h"
#include "NiColor_e5e1ad7d.h"
#include "NiPoint3.h"
struct DIRECTIONAL_DATA {
    float falloffScale;
    float falloffBias;
    float noiseUVScale;
    float materialUVScale;
    NiPoint3 ProjectionDir;
    float normalDampener;
    NiColor_e5e1ad7d singlePassColor;
    int singlePass;
    Flag_a4a94b8a flags;
    unsigned int unk2C;
};
static_assert(sizeof(DIRECTIONAL_DATA) == 56, "DIRECTIONAL_DATA layout differs from the PDB");
