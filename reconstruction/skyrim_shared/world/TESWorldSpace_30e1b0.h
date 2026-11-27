// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// TESWorldSpace, ShortPoint, NiPoint2, NiPoint3, WORLD_MAP_OFFSET_DATA, flags, fixedCenter, worldMapOffsetData, minimumCoords, maximumCoords: CRASHLOGGER_PDB(59818@2026.10.24)
// ApplyWorldMapOffset, x, y, z, mapScale, mapOffsetX, mapOffsetY, mapOffsetZ, unknown000, unknown0A1, unknown0A8, unknown1B4: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

struct ShortPoint
{
    std::int16_t x;  // 00
    std::int16_t y;  // 02
};
static_assert(sizeof(ShortPoint) == 0x4, "ShortPoint size");

struct NiPoint2
{
    float x;  // 00
    float y;  // 04
};
static_assert(sizeof(NiPoint2) == 0x8, "NiPoint2 size");

struct NiPoint3
{
    float x;  // 00
    float y;  // 04
    float z;  // 08
};
static_assert(sizeof(NiPoint3) == 0xC, "NiPoint3 size");

struct WORLD_MAP_OFFSET_DATA
{
    float mapScale;    // 00
    float mapOffsetX;  // 04
    float mapOffsetY;  // 08
    float mapOffsetZ;  // 0C
};
static_assert(sizeof(WORLD_MAP_OFFSET_DATA) == 0x10, "WORLD_MAP_OFFSET_DATA size");

class TESWorldSpace
{
public:
    void ApplyWorldMapOffset(NiPoint3& position, bool reverse) const;

    std::uint8_t          unknown000[0xA0];    // 000
    std::uint8_t          flags;               // 0A0
    std::uint8_t          unknown0A1[0x3];     // 0A1
    ShortPoint            fixedCenter;         // 0A4
    std::uint8_t          unknown0A8[0xFC];    // 0A8
    WORLD_MAP_OFFSET_DATA worldMapOffsetData;  // 1A4
    std::uint8_t          unknown1B4[0xC];     // 1B4
    NiPoint2              minimumCoords;       // 1C0
    NiPoint2              maximumCoords;       // 1C8
};
static_assert(offsetof(TESWorldSpace, flags) == 0xA0, "flags offset");
static_assert(offsetof(TESWorldSpace, fixedCenter) == 0xA4, "fixedCenter offset");
static_assert(offsetof(TESWorldSpace, worldMapOffsetData) == 0x1A4, "worldMapOffsetData offset");
static_assert(offsetof(TESWorldSpace, minimumCoords) == 0x1C0, "minimumCoords offset");
static_assert(offsetof(TESWorldSpace, maximumCoords) == 0x1C8, "maximumCoords offset");
