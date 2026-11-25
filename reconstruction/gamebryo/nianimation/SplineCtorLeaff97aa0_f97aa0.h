// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiBSplineInterpolator: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets observed on the target.
#pragma once
#include <cstdint>
struct SplineRefTargetf97aa0
{
    void* table;
    // volatile: the target updates the reference count atomically.
    volatile long count;
};
class SplineBasef97aa0
{
public:
    SplineBasef97aa0();
    virtual ~SplineBasef97aa0();
    std::uint8_t state[0x10];
};
class SplineCtorLeaff97aa0 : public SplineBasef97aa0
{
public:
    SplineCtorLeaff97aa0(SplineRefTargetf97aa0* data, SplineRefTargetf97aa0* basis);
    float minimum;
    float maximum;
    SplineRefTargetf97aa0* data;
    SplineRefTargetf97aa0* basis;
};
