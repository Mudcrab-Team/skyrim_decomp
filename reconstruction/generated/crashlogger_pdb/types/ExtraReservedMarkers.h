// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraReservedMarkers; size 0x30
#pragma once

#include "BSExtraData_4ca6af76.h"
#include "BSTArray_RE__MarkerUsedData_de10c4ce.h"
struct ExtraReservedMarkers {
    BSExtraData_4ca6af76 _base;
    BSTArray_RE__MarkerUsedData_de10c4ce reservedMarkerArray;
    unsigned long long unk28;
};
static_assert(sizeof(ExtraReservedMarkers) == 48, "ExtraReservedMarkers layout differs from the PDB");
