// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiFloatKey; size 0x8
#pragma once

#include "NiAnimationKey.h"
struct NiFloatKey {
    NiAnimationKey _base;
    float _value;
};
static_assert(sizeof(NiFloatKey) == 8, "NiFloatKey layout differs from the PDB");
