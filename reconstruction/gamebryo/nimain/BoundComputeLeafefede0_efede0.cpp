// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xefede0 BoundComputeLeafefede0::ComputeMinimalBound
#include "BoundComputeLeafefede0_efede0.h"

void BoundComputeLeafefede0::ComputeMinimalBound(BoundArrayefede0& bounds)
{
    const auto* first = bounds.values[0];
    x = first->x;
    y = first->y;
    z = first->z;
    radius = first->radius;
    for (std::uint32_t index = 1; index < bounds.count; ++index) {
        Merge(bounds.values[index]);
    }
}
