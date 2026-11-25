// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiEulerRotKey, FillDerivedVals: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets observed on the target.
#pragma once
#include <cstdint>
extern void (*gEulerFillFunctionsf6e440[])(void*, std::uint32_t, std::uint8_t);
struct EulerFillLeaff6e440
{
    static void FillDerivedVals(EulerFillLeaff6e440* keys, std::uint32_t count, std::uint8_t stride);
    std::uint8_t unknown00[0x14];
    std::uint32_t counts[3];
    std::int32_t types[3];
    std::uint8_t strides[3];
    std::uint8_t unknown2f;
    void* keys[3];
};
