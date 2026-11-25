// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiBlendInterpolator, GetHighestWeightedIndex: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets and stride observed on the target
#pragma once
#include <cstdint>

struct BlendIndexItem
{
    void* interpolator;
    std::uint32_t unknown08;
    float weight;
    std::uint8_t unknown10[0x10];
};
struct BlendIndexLeaff5c9a0
{
    std::uint8_t GetHighestWeightedIndex() const;
    std::uint8_t unknown00[0x19];
    std::uint8_t arraySize;
    std::uint8_t count;
    std::uint8_t singleIndex;
    BlendIndexItem* items;
};
