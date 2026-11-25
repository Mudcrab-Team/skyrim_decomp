// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf75180 ArrayRefDtorLeaff75180::~ArrayRefDtorLeaff75180
#include "ArrayRefDtorLeaff75180_f75180.h"
#include <intrin.h>

ArrayRefBasef75180::~ArrayRefBasef75180()
{
    // The reference-object counter is updated atomically.
    // The reference-object counter is updated atomically.
    _InterlockedDecrement(&gArrayRefCountf75180);
}
ArrayRefDtorLeaff75180::~ArrayRefDtorLeaff75180()
{
    delete[] elements;
}
