// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiBound, ComputeMinimalBound: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets observed on the target.
#pragma once
#include <cstdint>
struct BoundComputeLeafefede0;
struct BoundArrayefede0
{
    std::uint64_t unknown00;
    const BoundComputeLeafefede0** values;
    std::uint16_t unknown10;
    std::uint16_t count;
};
struct BoundComputeLeafefede0
{
    void ComputeMinimalBound(BoundArrayefede0& bounds);
    void Merge(const BoundComputeLeafefede0* other);
    float x;
    float y;
    float z;
    float radius;
};
