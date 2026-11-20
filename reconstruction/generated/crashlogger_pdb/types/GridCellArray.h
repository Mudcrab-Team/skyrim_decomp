// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GridCellArray; size 0x30
#pragma once

#include "GridArray.h"
#include "NiPoint3.h"
struct TESObjectCELL_f81013b3;
struct GridCellArray {
    GridArray _base;
    TESObjectCELL_f81013b3** cells;
    NiPoint3 worldCenter;
    bool land3DAttached;
    unsigned char undefined_2d[3];
};
static_assert(sizeof(GridCellArray) == 48, "GridCellArray layout differs from the PDB");
