// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiBackToFrontAccumulator; size 0x50
#pragma once

#include "NiAccumulator.h"
#include "NiTPointerList_RE__BSGeometry_0ab365c7.h"
struct BSGeometry;
struct NiBackToFrontAccumulator {
    NiAccumulator _base;
    NiTPointerList_RE__BSGeometry_0ab365c7 itemsList;
    int numItems;
    int maxItems;
    BSGeometry** items;
    float* depths;
    int currItem;
    unsigned char undefined_4c[4];
};
static_assert(sizeof(NiBackToFrontAccumulator) == 80, "NiBackToFrontAccumulator layout differs from the PDB");
