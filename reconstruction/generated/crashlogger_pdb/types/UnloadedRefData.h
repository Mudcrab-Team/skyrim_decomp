// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: UnloadedRefData; size 0xc
#pragma once

#include "CellKey.h"
struct UnloadedRefData {
    unsigned int refID;
    unsigned int parentSpaceID;
    CellKey cellKey;
};
static_assert(sizeof(UnloadedRefData) == 12, "UnloadedRefData layout differs from the PDB");
