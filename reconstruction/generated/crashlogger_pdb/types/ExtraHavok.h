// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraHavok; size 0x20
#pragma once

#include "BSExtraData_4ca6af76.h"
#include "NiPointer_RE__CellMopp_4466d7a1.h"
#include "NiPointer_RE__bhkWorld_6bd44506.h"
struct ExtraHavok {
    BSExtraData_4ca6af76 _base;
    NiPointer_RE__bhkWorld_6bd44506 world;
    NiPointer_RE__CellMopp_4466d7a1 cellMopp;
};
static_assert(sizeof(ExtraHavok) == 32, "ExtraHavok layout differs from the PDB");
