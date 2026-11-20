// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSBound; size 0x30
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "NiExtraData.h"
#include "NiPoint3_a7124070.h"
struct BSBound {
    NiExtraData _base;
    NiPoint3_a7124070 center;
    NiPoint3_a7124070 extents;
};
static_assert(sizeof(BSBound) == 48, "BSBound layout differs from the PDB");
