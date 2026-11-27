// Exposure detail: (local binary analysis and permitted symbol/layout hints).
// Source exposure: mixed
// Target: sse-steam-1-7-104, RVA 0xbafa60; image SHA-256
// 846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f.
// Code origin: original handwritten reconstruction from the assigned local pack; no adapted bodies.
// BGSGamebryoSequenceGenerator: CRASHLOGGER_PDB(59818@2026.10.24)
// GetBlendPercentage: SYMBOLS(tesv-2013-map)
// GetBlendPercentage: SYMBOLS(fo4-pdb)
// GetBlendPercentage: GUESS(medium); assignment of the published candidate name
// blendMode, blendPercentage, prefix: GUESS(low); descriptive storage names;
// blendMode, blendPercentage: SYMBOLS(fo4-pdb); semantic layout hints only
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json.
// 0xbafa60 BGSGamebryoSequenceGenerator::GetBlendPercentage

#pragma once
#include <cstddef>
#include <cstdint>

class BGSGamebryoSequenceGenerator
{
public:
    float GetBlendPercentage() const;

    std::uint8_t prefix[0x50];
    std::int8_t blendMode;  // 50
    std::uint8_t modePadding[3];
    float blendPercentage;  // 54
};
static_assert(offsetof(BGSGamebryoSequenceGenerator, blendMode) == 0x50, "blend mode offset");
static_assert(offsetof(BGSGamebryoSequenceGenerator, blendPercentage) == 0x54, "blend percentage offset");
