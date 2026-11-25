// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf81890 ArrayRefDtorLeaff81890::~ArrayRefDtorLeaff81890
#include "ArrayRefDtorLeaff81890_f81890.h"
#include <intrin.h>

ArrayRefBasef81890::~ArrayRefBasef81890()
{
    // The reference-object counter is updated atomically.
    // The reference-object counter is updated atomically.
    _InterlockedDecrement(&gArrayRefCountf81890);
}
ArrayRefDtorLeaff81890::~ArrayRefDtorLeaff81890()
{
    delete[] elements;
}
