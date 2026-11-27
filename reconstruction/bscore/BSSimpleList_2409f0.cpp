// Source exposure: mixed (sibling game-code declarations; the pinned image listing).
// Code origin: adapted from the sibling list header, then checked against the image listing.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x2409f0 BSSimpleList<MESSAGEBOX_BUTTON*>::AddHead
// Adapted bodies: BSSimpleList::AddHead (fo4-private@1b765c70 src/BSCore/BSSimpleList.h:112), listed in the header.
#include "BSSimpleList_2409f0.h"

template void BSSimpleList<MESSAGEBOX_BUTTON*>::AddHead(MESSAGEBOX_BUTTON* const&, BSSimpleList<MESSAGEBOX_BUTTON*>* (*)(MESSAGEBOX_BUTTON*, void*), void*);
