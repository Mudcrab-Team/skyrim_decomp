// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: WeatherType; size 0x18
#pragma once

struct TESGlobal_18239760;
struct TESWeather;
struct WeatherType {
    TESWeather* Weather_0;
    int Chance_8;
    char _pad_C[4];
    TESGlobal_18239760* Global_10;
};
static_assert(sizeof(WeatherType) == 24, "WeatherType layout differs from the PDB");
