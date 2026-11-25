// Source exposure: mixed (community-generated layout; pinned image observations).
// Code origin: original; local observations and generated layout declarations only
// TESWorldSpace, maximumCoords: CRASHLOGGER_PDB(59818@2026.10.24)
// Function30d9b0, FloorToCell: GUESS(low)
// 0x30d9b0 TESWorldSpace::Function30d9b0
// Adapted bodies: none
#include "TESWorldSpace_30d9b0.h"

// Floor of a world coordinate, shifted down to a cell index.
static inline std::int32_t FloorToCell(float value)
{
    float truncated = static_cast<float>(static_cast<std::int32_t>(value));
    float floored = value - truncated >= 0.0f ? truncated : truncated - 1.0f;
    return static_cast<std::int32_t>(floored) >> 12;
}

void TESWorldSpace::Function30d9b0(std::int32_t& a_x, std::int32_t& a_y) const
{
    a_x = FloorToCell(maximumCoords.x);
    a_y = FloorToCell(maximumCoords.y);
}
