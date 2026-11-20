// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiTransform; size 0x34
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "NiMatrix3.h"
#include "NiPoint3.h"
struct NiTransform {
    NiMatrix3 rotate;
    NiPoint3 translate;
    float scale;
};
static_assert(sizeof(NiTransform) == 52, "NiTransform layout differs from the PDB");
