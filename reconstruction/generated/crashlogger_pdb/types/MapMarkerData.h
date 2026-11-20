// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MapMarkerData; size 0x18
#pragma once

#include "TESFullName.h"
struct MapMarkerData {
    TESFullName locationName;
    unsigned char flags;  // Flag in the PDB is wider than this slot
    unsigned char pad11;
    unsigned short type;  // MARKER_TYPE in the PDB is wider than this slot
    unsigned int pad14;
};
static_assert(sizeof(MapMarkerData) == 24, "MapMarkerData layout differs from the PDB");
