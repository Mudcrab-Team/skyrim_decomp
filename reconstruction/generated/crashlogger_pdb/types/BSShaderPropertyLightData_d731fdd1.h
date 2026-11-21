// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSShaderPropertyLightData; size 0x28
// one of 2 different PDB types sharing this name
#pragma once

#include "BSTArray_RE__BSLight_d206b33f_151e133f.h"
struct BSShaderPropertyLightData_d731fdd1 {
    BSTArray_RE__BSLight_d206b33f_151e133f lights;
    int lightListFence;
    unsigned int activeLightMask;
    bool lightListChanged;
    unsigned char undefined_21[7];
};
static_assert(sizeof(BSShaderPropertyLightData_d731fdd1) == 40, "BSShaderPropertyLightData_d731fdd1 layout differs from the PDB");
