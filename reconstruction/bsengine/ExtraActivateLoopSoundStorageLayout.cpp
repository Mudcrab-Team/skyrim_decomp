// Source exposure: mixed (represented community declarations and local binary analysis).
// BSExtraDataStorageLayout, ExtraActivateLoopSoundStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraActivateLoopSound.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x17c0d0 DeletingLeaf17c0d0::~DeletingLeaf17c0d0
void operator delete(void*, unsigned __int64) noexcept;
#include "ExtraActivateLoopSoundStorageLayout.h"
namespace ResearchLayouts {
inline BSExtraDataStorageLayout::~BSExtraDataStorageLayout() {}
inline ExtraActivateLoopSoundStorageLayout::~ExtraActivateLoopSoundStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::ExtraActivateLoopSoundStorageLayout) == 32, "independently observed allocation size");
static ResearchLayouts::ExtraActivateLoopSoundStorageLayout object;
