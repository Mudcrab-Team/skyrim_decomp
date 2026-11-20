// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESRegionDataWeather; size 0x20
#pragma once

#include "BSSimpleList_RE__WeatherType_a132f962.h"
#include "TESRegionData.h"
struct TESRegionDataWeather {
    TESRegionData _base;
    BSSimpleList_RE__WeatherType_a132f962 weatherTypes;
};
static_assert(sizeof(TESRegionDataWeather) == 32, "TESRegionDataWeather layout differs from the PDB");
