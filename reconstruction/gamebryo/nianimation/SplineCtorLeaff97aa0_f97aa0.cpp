// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf97aa0 SplineCtorLeaff97aa0::SplineCtorLeaff97aa0
#include "SplineCtorLeaff97aa0_f97aa0.h"
#include <cfloat>
#include <intrin.h>

SplineCtorLeaff97aa0::SplineCtorLeaff97aa0(SplineRefTargetf97aa0* dataValue, SplineRefTargetf97aa0* basisValue)
    : minimum(FLT_MAX), maximum(-FLT_MAX), data(dataValue)
{
    if (data) {
        // Increment the new reference count atomically.
        _InterlockedIncrement(&data->count);
    }
    basis = basisValue;
    if (basis) {
        // Increment the new reference count atomically.
        _InterlockedIncrement(&basis->count);
    }
}
