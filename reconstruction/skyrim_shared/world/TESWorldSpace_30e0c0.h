// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// TESWorldSpace, WORLD_MAP_DATA, parentUseFlags, parentWorld, worldMapData, GetWorldMapData: CRASHLOGGER_PDB(59818@2026.10.24)
// usableWidth, usableHeight, nwCellX, nwCellY, seCellX, seCellY, minHeight, maxHeight, initialPitch, HasParentUseFlag, ResolveParentWorld, unknown000, unknown0A4, unknown160: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

struct WORLD_MAP_DATA
{
    std::uint32_t usableWidth;   // 00
    std::uint32_t usableHeight;  // 04
    std::int16_t  nwCellX;       // 08
    std::int16_t  nwCellY;       // 0A
    std::int16_t  seCellX;       // 0C
    std::int16_t  seCellY;       // 0E
    float         minHeight;     // 10
    float         maxHeight;     // 14
    float         initialPitch;  // 18
};
static_assert(sizeof(WORLD_MAP_DATA) == 0x1C, "WORLD_MAP_DATA size");

class TESWorldSpace
{
public:
    WORLD_MAP_DATA* GetWorldMapData();

    std::uint8_t   unknown000[0xA2];  // 000
    std::uint16_t  parentUseFlags;    // 0A2
    std::uint8_t   unknown0A4[0xB4];  // 0A4
    TESWorldSpace* parentWorld;       // 158
    std::uint8_t   unknown160[0x28];  // 160
    WORLD_MAP_DATA worldMapData;      // 188
};
static_assert(offsetof(TESWorldSpace, parentUseFlags) == 0xA2, "parentUseFlags offset");
static_assert(offsetof(TESWorldSpace, parentWorld) == 0x158, "parentWorld offset");
static_assert(offsetof(TESWorldSpace, worldMapData) == 0x188, "worldMapData offset");
