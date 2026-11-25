// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiFloatData, SetAnim: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); used offsets observed on the target
#pragma once
#include <cstdint>

struct FloatKeyLeaf;
extern std::uint8_t gFloatKeySizes[];
struct FloatDataLeaff60d90
{
    void SetAnim(FloatKeyLeaf* newKeys, std::uint32_t newCount, std::int32_t newType);
    std::uint8_t unknown00[0x10];
    std::uint32_t count;
    FloatKeyLeaf* keys;
    std::int32_t type;
    std::uint8_t keySize;
};
