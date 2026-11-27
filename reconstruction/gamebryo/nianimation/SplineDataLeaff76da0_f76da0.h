// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiBSplineData, IsEqual: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets observed on the target
#pragma once
#include <cstdint>

struct SplineObject { std::uint8_t state[0x20]; };
struct SplineBase : SplineObject { bool IsEqual(SplineObject* other); };
struct SplineDataLeaff76da0 : SplineBase
{
    bool IsEqual(SplineObject* other);
    std::uint32_t count;
    std::uint32_t compactCount;
};
