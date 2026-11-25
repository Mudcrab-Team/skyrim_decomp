// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf77810 SplineDataDtorLeaff77810::~SplineDataDtorLeaff77810
#include "SplineDataDtorLeaff77810_f77810.h"
#include <intrin.h>

SplineDataBasef77810::~SplineDataBasef77810()
{
    // The reference-object counter is updated atomically.
    // The reference-object counter is updated atomically.
    _InterlockedDecrement(&gSplineDataCountf77810);
}
SplineDataDtorLeaff77810::SplineDataDtorLeaff77810() = default;
SplineDataDtorLeaff77810::~SplineDataDtorLeaff77810()
{
    ReleaseSplineMemoryf77810(first);
    ReleaseSplineMemoryf77810(second);
}
