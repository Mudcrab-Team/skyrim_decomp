// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSShaderPropertyLightData; size 0x28
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSTArray_RE__BSLight_d206b33f.h"
struct BSShaderPropertyLightData {
    BSTArray_RE__BSLight_d206b33f lights;
    int lightListFence;
    unsigned int activeLightMask;
    bool lightListChanged;
    unsigned char undefined_21[7];
};
static_assert(sizeof(BSShaderPropertyLightData) == 40, "BSShaderPropertyLightData layout differs from the PDB");
