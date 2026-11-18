// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none
// 0xfdb1f0 BSPortalGraphEntry::~BSPortalGraphEntry
#include "BSPortalGraphEntry.h"

// Not compared on its own: the compiler emits the vftable here, and with it the deleting
// destructor that is compared. The destructor itself stays undefined here so that the compiler
// calls the separate complete destructor, as the listing does.
BSPortalGraphEntry::BSPortalGraphEntry()
{
}
