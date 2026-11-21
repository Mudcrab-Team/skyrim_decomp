// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: OBJ_LIGH; size 0x28
#pragma once

#include "Color_aa361e09.h"
#include "TES_LIGHT_FLAGS.h"
struct OBJ_LIGH {
    int time;
    unsigned int radius;
    Color_aa361e09 color;
    TES_LIGHT_FLAGS flags;
    float fallofExponent;
    float fov;
    float nearDistance;
    float flickerPeriodRecip;
    float flickerIntensityAmplitude;
    float flickerMovementAmplitude;
};
static_assert(sizeof(OBJ_LIGH) == 40, "OBJ_LIGH layout differs from the PDB");
