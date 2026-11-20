// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiColorInterpolator; size 0x38
#pragma once

#include "NiColorA_7eee66f4.h"
#include "NiKeyBasedInterpolator.h"
#include "NiPointer_RE__NiColorData_df5fb1f3.h"
struct NiColorInterpolator {
    NiKeyBasedInterpolator _base;
    NiColorA_7eee66f4 colorValue;
    NiPointer_RE__NiColorData_df5fb1f3 colorData;
    unsigned int lastIndex;
    unsigned int pad34;
};
static_assert(sizeof(NiColorInterpolator) == 56, "NiColorInterpolator layout differs from the PDB");
