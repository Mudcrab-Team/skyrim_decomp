// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSBound; size 0x30
// one of 2 different PDB types sharing this name
#pragma once

#include "NiExtraData_b2385dce.h"
#include "NiPoint3.h"
struct BSBound_d0847efa {
    NiExtraData_b2385dce _base;
    NiPoint3 center;
    NiPoint3 extents;
};
static_assert(sizeof(BSBound_d0847efa) == 48, "BSBound_d0847efa layout differs from the PDB");
