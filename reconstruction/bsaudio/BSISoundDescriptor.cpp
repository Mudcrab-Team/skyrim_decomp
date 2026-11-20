// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x32ac50 BSISoundDescriptor::~BSISoundDescriptor
#include "BSISoundDescriptor.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BSISoundDescriptor::BSISoundDescriptor()
{
}

// RVA 0x32ac50, 43 bytes, BSISoundDescriptor::~BSISoundDescriptor: the target inlines the complete
// destructor (vftable store, then class-scope delete), so the destructor is an empty inline body in
// the header.
