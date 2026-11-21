// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ImageSpaceModifierInstanceTemp; size 0x30
#pragma once

#include "ImageSpaceModifierInstance.h"
struct ImageSpaceModifierInstanceTemp {
    ImageSpaceModifierInstance _base;
    float duration;
    unsigned int pad3C;
};
static_assert(sizeof(ImageSpaceModifierInstanceTemp) == 48, "ImageSpaceModifierInstanceTemp layout differs from the PDB");
