// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0xebeb10 BSFile::~BSFile
#include "BSFile.h"

// Not compared on its own: the compiler emits the vftable here, and with it the deleting
// destructor that is compared. The destructor itself stays undefined here so that the compiler
// calls the separate complete destructor, as the listing does.
BSFile::BSFile()
{
}
