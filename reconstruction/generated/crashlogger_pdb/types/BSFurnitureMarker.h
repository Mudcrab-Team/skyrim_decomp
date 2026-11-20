// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSFurnitureMarker; size 0x14
#pragma once

#include "NiPoint3.h"
struct BSFurnitureMarker {
    NiPoint3 offset;
    float heading;
    unsigned short animationType;  // AnimationType in the PDB is wider than this slot
    unsigned short entryProperties;  // EntryProperties in the PDB is wider than this slot
};
static_assert(sizeof(BSFurnitureMarker) == 20, "BSFurnitureMarker layout differs from the PDB");
