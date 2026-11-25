// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf76ef0 SplineDtorLeaff76ef0::~SplineDtorLeaff76ef0
#include "SplineDtorLeaff76ef0_f76ef0.h"
#include <intrin.h>

SplineDtorBase::~SplineDtorBase()
{
    // The reference-object counter is updated atomically.
    // The reference-object counter is updated atomically.
    _InterlockedDecrement(&gSplineObjectCount);
}

SplineDtorLeaff76ef0::~SplineDtorLeaff76ef0()
{
    ReleaseSplineStorage(first);
    ReleaseSplineStorage(second);
}
