// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Sky::Flags
#pragma once
enum class Sky__Flags : int {
    kNone = 0,
    kFastTravel = 16,
    kHideSky = 128,
    kUpdateSunriseBegin = 512,
    kUpdateSunriseEnd = 1024,
    kUpdateSunsetBegin = 2048,
    kUpdateSunsetEnd = 4096,
    kUpdateColorsSunriseBegin = 8192,
    kUpdateColorsSunsetEnd = 16384,
    kUpdateWind = 1048576,
    kReleaseWeatherOverride = 2097152,
};
