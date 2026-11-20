// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: REFR_LIGHT; size 0x10
#pragma once

#include "NiPointer_RE__NiLight_e90f0c52.h"
struct REFR_LIGHT {
    NiPointer_RE__NiLight_e90f0c52 light;
    float wantDimmer;
    unsigned int pad0C;
};
static_assert(sizeof(REFR_LIGHT) == 16, "REFR_LIGHT layout differs from the PDB");
