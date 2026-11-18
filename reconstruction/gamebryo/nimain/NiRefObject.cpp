// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x213be0 NiRefObject::~NiRefObject
#include <intrin.h>

#include "NiRefObject.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
NiRefObject::NiRefObject()
{
}

NiRefObject::~NiRefObject()
{
    // the object count is shared across threads, so the decrement must be atomic
    _InterlockedDecrement(&niRefObjectTotalCount);
}
