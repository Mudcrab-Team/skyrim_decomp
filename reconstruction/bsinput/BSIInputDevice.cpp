// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0xcfc0b0 BSIInputDevice::~BSIInputDevice
#include "BSIInputDevice.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BSIInputDevice::BSIInputDevice()
{
}

// RVA 0xcfc0b0, 43 bytes, BSIInputDevice::~BSIInputDevice: the target inlines the complete
// destructor (vftable store, then class-scope delete), so the destructor is an empty inline body in
// the header.
