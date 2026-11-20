// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESWeather::WeatherSoundList; size 0x10
#pragma once

struct BSSimpleList_TESWeather__SoundData;
struct TESWeather__SoundData;
struct TESWeather__WeatherSoundList {
    TESWeather__SoundData* Item_0;
    BSSimpleList_TESWeather__SoundData* Next_8;
};
static_assert(sizeof(TESWeather__WeatherSoundList) == 16, "TESWeather__WeatherSoundList layout differs from the PDB");
