// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiColorKey; size 0x14
#pragma once

#include "NiAnimationKey.h"
#include "NiColorA_7eee66f4.h"
struct NiColorKey {
    NiAnimationKey _base;
    NiColorA_7eee66f4 _color;
};
static_assert(sizeof(NiColorKey) == 20, "NiColorKey layout differs from the PDB");
