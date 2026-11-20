// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSUtilityShader; size 0x98
#pragma once

#include "BSShader.h"
struct BSUtilityShader {
    BSShader _base;
    unsigned int currentTechnique;
    unsigned int currentTechniqueMask;
};
static_assert(sizeof(BSUtilityShader) == 152, "BSUtilityShader layout differs from the PDB");
