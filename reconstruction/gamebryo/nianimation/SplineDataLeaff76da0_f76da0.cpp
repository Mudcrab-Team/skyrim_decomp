// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf76da0 SplineDataLeaff76da0::IsEqual
#include "SplineDataLeaff76da0_f76da0.h"

bool SplineDataLeaff76da0::IsEqual(SplineObject* other)
{
    const auto* spline = static_cast<SplineDataLeaff76da0*>(other);
    if (SplineBase::IsEqual(other)) {
        if (spline->count == count && spline->compactCount == compactCount) {
            return true;
        }
    }
    return false;
}
