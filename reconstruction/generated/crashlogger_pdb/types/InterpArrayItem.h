// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: InterpArrayItem; size 0x20
#pragma once

#include "NiPointer_RE__NiInterpController_422c865f.h"
#include "NiPointer_RE__NiInterpolator_9f4d6cb5.h"
struct NiBlendInterpolator_1a2c7cb7;
struct InterpArrayItem {
    NiPointer_RE__NiInterpolator_9f4d6cb5 interpolator;
    NiPointer_RE__NiInterpController_422c865f interpCtlr;
    NiBlendInterpolator_1a2c7cb7* blendInterp;
    unsigned char blendIdx;
    unsigned char pad19;
    unsigned short pad1A;
    unsigned int pad1C;
};
static_assert(sizeof(InterpArrayItem) == 32, "InterpArrayItem layout differs from the PDB");
