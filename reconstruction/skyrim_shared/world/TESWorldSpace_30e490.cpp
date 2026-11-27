// Source exposure: mixed (community declarations; permitted sibling game code; pinned image observations).
// Code origin: adapted parent lookup shape from the pinned FNV sibling
// SPDX-License-Identifier: CC0-1.0
// 0x30e490 TESWorldSpace::GetLODWaterType
// GetLODWaterType, GetParentWorld, GetParentUseFlag: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0)
// Adapted bodies: GetLODWaterType, GetParentWorld, GetParentUseFlag; momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesworldspace.cpp (CC0-1.0); GetParentWorld also follows momusdigital/f3_decomp@f5bac1b5 src/fallout_shared/tesworldspace.cpp (CC0-1.0)
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesworldspace.cpp:946
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesworldspace.cpp:80
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesworldspace.cpp:960
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/fallout_shared/tesworldspace.cpp:28
#include "TESWorldSpace_30e490.h"

bool TESWorldSpace::GetParentUseFlag(std::uint32_t bit) const
{
    const std::uint16_t mask = static_cast<std::uint16_t>(1u << bit);
    return (parentUseFlags & mask) != 0;
}

TESWorldSpace* TESWorldSpace::GetParentWorld(std::uint32_t bit)
{
    if (parentWorld && !GetParentUseFlag(bit)) {
        return nullptr;
    }
    return parentWorld;
}

TESWaterForm* TESWorldSpace::GetLODWaterType()
{
    if (GetParentWorld(1)) {
        return GetParentWorld(1)->GetLODWaterType();
    }
    if (lodWater) {
        return lodWater;
    }
    return defaultWater;
}
