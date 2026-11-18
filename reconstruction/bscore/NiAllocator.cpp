// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
// 0xeae960 NiAllocator::~NiAllocator
#include "NiAllocator.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
NiAllocator::NiAllocator()
{
}

// RVA 0xeae960, 43 bytes, NiAllocator::~NiAllocator; compared as the scalar deleting destructor.
// The target stores the vftable and frees the object itself, so the complete destructor is empty.
NiAllocator::~NiAllocator()
{
}
