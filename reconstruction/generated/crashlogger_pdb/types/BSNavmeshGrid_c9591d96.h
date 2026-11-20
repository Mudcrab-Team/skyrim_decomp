// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSNavmeshGrid; size 0x30
// one of 2 different PDB types sharing this name
#pragma once

#include "NiPoint3.h"
#include "SimpleArray_RE__BSTArray_unsigned_short_fa623690.h"
struct BSNavmeshGrid_c9591d96 {
    unsigned int gridSize;
    float columnSectionLen;
    float rowSectionLen;
    NiPoint3 gridBoundsMin;
    NiPoint3 gridBoundsMax;
    unsigned int pad24;
    SimpleArray_RE__BSTArray_unsigned_short_fa623690 gridData;
};
static_assert(sizeof(BSNavmeshGrid_c9591d96) == 48, "BSNavmeshGrid_c9591d96 layout differs from the PDB");
