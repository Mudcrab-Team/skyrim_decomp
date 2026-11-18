// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
// 0xfdb1b0 BSPortalGraph::~BSPortalGraph
#include "BSPortalGraph.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BSPortalGraph::BSPortalGraph()
{
}

// RVA 0xfdb1b0, 52 bytes: the destructor is declared in the header only. The target calls the
// complete base destructor first, then tests bit 0 of the flag argument before freeing the object.
