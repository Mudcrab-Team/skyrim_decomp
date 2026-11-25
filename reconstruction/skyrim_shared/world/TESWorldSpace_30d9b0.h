// Source exposure: mixed (community-generated layout; pinned image observations).
// Code origin: original; declarations from the generated CrashLogger layout
// TESWorldSpace, maximumCoords: CRASHLOGGER_PDB(59818@2026.10.24)
// Function30d9b0, unused00: GUESS(low)
// Adapted bodies: none
#pragma once
#include <cstddef>
#include <cstdint>

struct TESWorldSpace
{
    void Function30d9b0(std::int32_t& a_x, std::int32_t& a_y) const;

    std::uint8_t unused00[0x1C8];
    struct Coordinates
    {
        float x;
        float y;
    } maximumCoords;
};
static_assert(offsetof(TESWorldSpace, maximumCoords) == 0x1C8, "maximum coordinate offset");
