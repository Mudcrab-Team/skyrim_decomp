// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraMapMarker; size 0x18
#pragma once

#include "BSExtraData_4ca6af76.h"
struct MapMarkerData;
struct ExtraMapMarker {
    BSExtraData_4ca6af76 _base;
    MapMarkerData* mapData;
};
static_assert(sizeof(ExtraMapMarker) == 24, "ExtraMapMarker layout differs from the PDB");
