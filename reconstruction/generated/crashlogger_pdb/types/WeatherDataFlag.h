// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: WeatherDataFlag
#pragma once
enum class WeatherDataFlag : int {
    kNone = 0,
    kPleasant = 1,
    kCloudy = 2,
    kRainy = 4,
    kSnow = 8,
    kPermAurora = 16,
    kAuroraFollowsSun = 32,
};
