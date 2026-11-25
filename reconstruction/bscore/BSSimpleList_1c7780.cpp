// Source exposure: mixed (sibling game-code declarations; the pinned image listing).
// Code origin: adapted from the sibling list header, then checked against the image listing.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x1c7780 BSSimpleList<TESPackage*>::AddTail
// Adapted bodies: BSSimpleList::AddTail (fo4-private@1b765c70 src/BSCore/BSSimpleList.h:210), listed in the header.
#include "BSSimpleList_1c7780.h"

template void BSSimpleList<TESPackage*>::AddTail(TESPackage* const&, BSSimpleList<TESPackage*>* (*)(TESPackage*, void*), void*);
