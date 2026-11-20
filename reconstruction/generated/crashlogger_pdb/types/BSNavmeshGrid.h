// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSNavmeshGrid; size 0x30
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "NiPoint3_a7124070.h"
struct BSNavmeshGrid {
    unsigned int gridSize;
    float columnSectionLen;
    float rowSectionLen;
    NiPoint3_a7124070 gridBoundsMin;
    float ColumnSectionLen_4;
    float RowSectionLen_8;
    unsigned char undefined_20[4];
    unsigned int pad24;
    unsigned char undefined_28[4];
    int GridSize_0;
};
static_assert(sizeof(BSNavmeshGrid) == 48, "BSNavmeshGrid layout differs from the PDB");
