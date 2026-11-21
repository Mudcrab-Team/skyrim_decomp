// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: RadialBlur; size 0x28
#pragma once

#include "NiPointer_RE__NiFloatInterpolator_1dc0cc15.h"
struct RadialBlur {
    NiPointer_RE__NiFloatInterpolator_1dc0cc15 strength;
    NiPointer_RE__NiFloatInterpolator_1dc0cc15 rampUp;
    NiPointer_RE__NiFloatInterpolator_1dc0cc15 start;
    NiPointer_RE__NiFloatInterpolator_1dc0cc15 rampDown;
    NiPointer_RE__NiFloatInterpolator_1dc0cc15 downStart;
};
static_assert(sizeof(RadialBlur) == 40, "RadialBlur layout differs from the PDB");
