// Source exposure: mixed (community declarations; permitted sibling game code; pinned image observations).
// Code origin: original layout view with labelled declarations
// SPDX-License-Identifier: CC0-1.0
// TESWorldSpace, TESWaterForm, parentWorld, parentUseFlags, worldWater: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// GetWaterType: SIBLING(fo4-private@1b765c70, author-permission)
// GetParentWorld, GetParentUseFlag: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0)
// defaultWater: GUESS(low)
#pragma once
#include <cstdint>
#include <cstddef>

class TESWaterForm;
extern TESWaterForm* defaultWater;

class TESWorldSpace
{
public:
    TESWaterForm* GetWaterType();
    TESWorldSpace* GetParentWorld(std::uint32_t bit);
    bool GetParentUseFlag(std::uint32_t bit) const;

    std::uint8_t padding00[0xa2];
    std::uint16_t parentUseFlags;
    std::uint8_t paddingA4[0xb4];
    TESWorldSpace* parentWorld;
    std::uint8_t padding160[0x8];
    TESWaterForm* worldWater;
};
static_assert(offsetof(TESWorldSpace, parentWorld) == 0x158, "parent offset");
static_assert(offsetof(TESWorldSpace, worldWater) == 0x168, "water offset");
