// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// 0x30e0c0 TESWorldSpace::GetWorldMapData
// Adapted bodies: none
#include "TESWorldSpace_30e0c0.h"

namespace
{
    bool HasParentUseFlag(const TESWorldSpace* world, std::uint32_t flagBit)
    {
        const std::uint16_t mask = static_cast<std::uint16_t>(1u << flagBit);
        return (world->parentUseFlags & mask) != 0;
    }

    TESWorldSpace* ResolveParentWorld(const TESWorldSpace* world, std::uint32_t flagBit)
    {
        if (world->parentWorld && !HasParentUseFlag(world, flagBit)) {
            return nullptr;
        }
        return world->parentWorld;
    }
}

// Return this worldspace's world map data, delegating to the parent worldspace when map data inheritance is set.
WORLD_MAP_DATA* TESWorldSpace::GetWorldMapData()
{
    if (ResolveParentWorld(this, 2)) {
        return ResolveParentWorld(this, 2)->GetWorldMapData();
    }
    return &worldMapData;
}
