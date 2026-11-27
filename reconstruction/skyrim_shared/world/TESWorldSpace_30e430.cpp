// Source exposure: mixed (community declarations; permitted sibling game code; pinned image observations).
// Code origin: adapted parent lookup shape from the pinned FNV sibling
// SPDX-License-Identifier: CC0-1.0
// 0x30e430 TESWorldSpace::GetWaterType
// GetWaterType: SIBLING(fo4-private@1b765c70, author-permission)
// GetParentWorld, GetParentUseFlag: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0)
// Adapted bodies: GetWaterType, GetParentWorld, GetParentUseFlag; momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesworldspace.cpp (CC0-1.0); GetParentWorld also follows momusdigital/f3_decomp@f5bac1b5 src/fallout_shared/tesworldspace.cpp (CC0-1.0)
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesworldspace.cpp:759
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesworldspace.cpp:80
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesworldspace.cpp:960
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESWorldSpace.cpp:149
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/fallout_shared/tesworldspace.cpp:28
#include "TESWorldSpace_30e430.h"

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

TESWaterForm* TESWorldSpace::GetWaterType()
{
    if (GetParentWorld(3)) {
        return GetParentWorld(3)->GetWaterType();
    }
    if (worldWater) {
        return worldWater;
    }
    return defaultWater;
}
