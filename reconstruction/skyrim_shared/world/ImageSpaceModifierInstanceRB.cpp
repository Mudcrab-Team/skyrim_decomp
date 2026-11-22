// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Code origin: names from meh321/AddressLibraryDatabase (permission); the compared body is the compiler-generated scalar deleting destructor from the listing
// 0x2a5670 ImageSpaceModifierInstanceRB::dtor
// Adapted bodies: none
#include "ImageSpaceModifierInstanceRB.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
ImageSpaceModifierInstanceRB::ImageSpaceModifierInstanceRB()
{
}

// ~ImageSpaceModifierInstanceRB stays declared but undefined: the compared deleting
// destructor calls the complete destructor out of line (cookbook rule 18).
