// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSPathingSearchAreaRestrictions; size 0x10
#pragma once

#include "NiPoint3.h"
struct BSPathingSearchAreaRestrictions {
    NiPoint3 center;
    float radius;
};
static_assert(sizeof(BSPathingSearchAreaRestrictions) == 16, "BSPathingSearchAreaRestrictions layout differs from the PDB");
