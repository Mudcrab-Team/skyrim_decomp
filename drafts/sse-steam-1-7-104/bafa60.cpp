// Near miss: 2.5 alignment distance | control-flow
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
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0xbafa60 BGSGamebryoSequenceGenerator::GetBlendPercentage

#include "include/bafa60/BGSGamebryoSequenceGenerator_bafa60.h"

// Select the configured blend mode and keep its percentage in the unit interval.
float BGSGamebryoSequenceGenerator::GetBlendPercentage() const
{
    float result;
    result = 1.0f;
    switch (static_cast<std::int32_t>(blendMode)) {
    case 1:
        result = blendPercentage;
        break;
    case 2:
        result -= blendPercentage;
        break;
    }
    if (!(result >= static_cast<float>(0.0f))) {
    return 0.0f;
} else {
        if (result > 1.0f) {
            return 1.0f;
        }
            return result;
    }
}
