// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraRank; size 0x18
#pragma once

#include "BSExtraData_4ca6af76.h"
struct ExtraRank {
    BSExtraData_4ca6af76 _base;
    int rank;
    unsigned int pad14;
};
static_assert(sizeof(ExtraRank) == 24, "ExtraRank layout differs from the PDB");
