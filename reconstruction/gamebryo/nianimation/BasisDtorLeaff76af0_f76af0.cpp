// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf76af0 BasisDtorLeaff76af0::~BasisDtorLeaff76af0
#include "BasisDtorLeaff76af0_f76af0.h"
#include <intrin.h>


BasisObjectBase::~BasisObjectBase()
{
    // The reference-object counter is updated atomically.
    _InterlockedDecrement(&gBasisObjectCount);
}

BasisDtorLeaff76af0::BasisDtorLeaff76af0() = default;
BasisDtorLeaff76af0::~BasisDtorLeaff76af0() = default;
