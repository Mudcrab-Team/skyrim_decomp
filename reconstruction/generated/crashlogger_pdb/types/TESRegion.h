// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESRegion; size 0x50
#pragma once

#include "NiColor_e5e1ad7d.h"
#include "TESForm.h"
struct RE__BSSimpleList_RE__TESRegionPointList_5f2e5e40;
struct TESRegionDataList;
struct TESWeather_4adb958d;
struct TESWorldSpace;
struct TESRegion {
    TESForm _base;
    TESRegionDataList* dataList;
    RE__BSSimpleList_RE__TESRegionPointList_5f2e5e40* pointLists;
    TESWorldSpace* worldSpace;
    TESWeather_4adb958d* currentWeather;
    NiColor_e5e1ad7d emittanceColor;
    unsigned int pad4C;
};
static_assert(sizeof(TESRegion) == 80, "TESRegion layout differs from the PDB");
