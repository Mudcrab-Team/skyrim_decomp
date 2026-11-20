// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSLensFlareRenderData; size 0x20
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSTArray_RE__NiPointer_RE__BSLensFlareSpriteRenderData_c3f31c83_40890bbe.h"
struct BSLensFlareRenderData {
    float fadeDistRadiusScale;
    float colorInfluence;
    BSTArray_RE__NiPointer_RE__BSLensFlareSpriteRenderData_c3f31c83_40890bbe sprites;
};
static_assert(sizeof(BSLensFlareRenderData) == 32, "BSLensFlareRenderData layout differs from the PDB");
