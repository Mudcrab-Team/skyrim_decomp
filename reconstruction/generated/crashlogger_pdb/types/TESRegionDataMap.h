// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESRegionDataMap; size 0x18
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "TESRegionData.h"
struct TESRegionDataMap {
    TESRegionData _base;
    BSFixedString_char_83b572b4 mapName;
};
static_assert(sizeof(TESRegionDataMap) == 24, "TESRegionDataMap layout differs from the PDB");
