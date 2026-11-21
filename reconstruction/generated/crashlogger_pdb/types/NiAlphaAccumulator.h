// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiAlphaAccumulator; size 0x58
#pragma once

#include "NiBackToFrontAccumulator.h"
struct NiAlphaAccumulator {
    NiBackToFrontAccumulator _base;
    bool observeNoSortHint;
    bool sortByClosestPoint;
    bool interfaceSort;
    unsigned char undefined_53[5];
};
static_assert(sizeof(NiAlphaAccumulator) == 88, "NiAlphaAccumulator layout differs from the PDB");
