// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MultiBoundMarkerData; size 0x20
#pragma once

#include "BSExtraData_4ca6af76.h"
#include "NiPoint3.h"
struct MultiBoundMarkerData {
    BSExtraData_4ca6af76 _base;
    NiPoint3 halfExtents;
    unsigned int pad1C;
};
static_assert(sizeof(MultiBoundMarkerData) == 32, "MultiBoundMarkerData layout differs from the PDB");
