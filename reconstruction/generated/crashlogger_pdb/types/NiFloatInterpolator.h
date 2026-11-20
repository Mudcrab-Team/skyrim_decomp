// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiFloatInterpolator; size 0x30
#pragma once

#include "NiKeyBasedInterpolator.h"
#include "NiPointer_RE__NiFloatData_426cc4c3.h"
struct NiFloatInterpolator {
    NiKeyBasedInterpolator _base;
    float floatValue;
    unsigned int pad1C;
    NiPointer_RE__NiFloatData_426cc4c3 floatData;
    unsigned int lastIndex;
    unsigned int pad2C;
};
static_assert(sizeof(NiFloatInterpolator) == 48, "NiFloatInterpolator layout differs from the PDB");
