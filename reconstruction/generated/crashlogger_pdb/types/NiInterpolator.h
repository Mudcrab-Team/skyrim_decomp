// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiInterpolator; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "NiObject.h"
struct NiInterpolator {
    NiObject _base;
    unsigned char undefined_10[4];
    unsigned int pad14;
};
static_assert(sizeof(NiInterpolator) == 24, "NiInterpolator layout differs from the PDB");
