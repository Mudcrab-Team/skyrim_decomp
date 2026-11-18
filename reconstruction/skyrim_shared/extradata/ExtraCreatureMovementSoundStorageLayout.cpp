// Source exposure: mixed (represented community declarations and local binary analysis).
// BSExtraDataStorageLayout, ExtraCreatureMovementSoundStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraCreatureMovementSound.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x17c6e0 DeletingLeaf17c6e0::~DeletingLeaf17c6e0
void operator delete(void*, unsigned __int64) noexcept;
#include "ExtraCreatureMovementSoundStorageLayout.h"
namespace ResearchLayouts {
inline BSExtraDataStorageLayout::~BSExtraDataStorageLayout() {}
inline ExtraCreatureMovementSoundStorageLayout::~ExtraCreatureMovementSoundStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::ExtraCreatureMovementSoundStorageLayout) == 32, "independently observed allocation size");
static ResearchLayouts::ExtraCreatureMovementSoundStorageLayout object;
