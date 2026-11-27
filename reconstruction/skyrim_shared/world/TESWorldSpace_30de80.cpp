// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// 0x30de80 TESWorldSpace::GetDefaultWaterHeight
// Adapted bodies: none
#include "TESWorldSpace_30de80.h"

namespace
{
    bool HasParentUseFlag(const TESWorldSpace* world, std::uint32_t flagBit)
    {
        const std::uint16_t mask = static_cast<std::uint16_t>(1u << flagBit);
        return (world->parentUseFlags & mask) != 0;
    }

    const TESWorldSpace* ResolveParentWorld(const TESWorldSpace* world, std::uint32_t flagBit)
    {
        if (world->parentWorld && !HasParentUseFlag(world, flagBit)) {
            return nullptr;
        }
        return world->parentWorld;
    }
}

// Return this worldspace's default water height, delegating to the parent worldspace when land data inheritance is set.
float TESWorldSpace::GetDefaultWaterHeight() const
{
    if (ResolveParentWorld(this, 0)) {
        return ResolveParentWorld(this, 0)->GetDefaultWaterHeight();
    }
    return defaultWaterHeight;
}
