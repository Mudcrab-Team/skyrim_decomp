// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x1527c0 MagicItemTraversalFunctor::~MagicItemTraversalFunctor
#include "MagicItemTraversalFunctor.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
MagicItemTraversalFunctor::MagicItemTraversalFunctor()
{
}

// The target inlines the complete destructor (vftable store, then a sized free of this), so the
// body is empty and the compiler emits the deleting form.
MagicItemTraversalFunctor::~MagicItemTraversalFunctor()
{
}
