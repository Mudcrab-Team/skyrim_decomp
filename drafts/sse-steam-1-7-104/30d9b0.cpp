// Near miss: 4.0 alignment distance | control-flow
// Exposure detail: (community-generated layout; pinned image observations).
// Source exposure: mixed
// Code origin: original; local observations and generated layout declarations only
// TESWorldSpace, maximumCoords: CRASHLOGGER_PDB(59818@2026.10.24)
// Function30d9b0: GUESS(low)
// Adapted bodies: none
// 0x30d9b0 TESWorldSpace::Function30d9b0

#include "include/30d9b0/TESWorldSpace_30d9b0.h"

void TESWorldSpace::Function30d9b0(std::int32_t& a_x, std::int32_t& a_y) const
{
    float x = static_cast<float>(static_cast<std::int32_t>(maximumCoords.x));
    if (!(maximumCoords.x - x >= 0.0f)) {
        x -= 1.0f;
    }
    a_x = static_cast<std::int32_t>(x) >> 12;

    float y = static_cast<float>(static_cast<std::int32_t>(maximumCoords.y));
    if (!(maximumCoords.y - y >= 0.0f)) {
        y -= 1.0f;
    }
    a_y = static_cast<std::int32_t>(y) >> 12;
}
