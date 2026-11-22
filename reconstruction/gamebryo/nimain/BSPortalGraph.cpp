// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: CC0-1.0
// 0xfda6e0 BSPortalGraph::Functionfda6e0
// Adapted bodies: none
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
#include "BSPortalGraph.h"

std::uint32_t BSPortalGraph::Functionfda6e0() const
{
    return member68;
}

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BSPortalGraph::BSPortalGraph()
{
}

// RVA 0xfdb1b0, 52 bytes: the destructor is declared in the header only. The target calls the
// complete base destructor first, then tests bit 0 of the flag argument before freeing the object.
