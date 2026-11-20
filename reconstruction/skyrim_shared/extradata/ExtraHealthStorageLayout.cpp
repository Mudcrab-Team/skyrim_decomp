// Source exposure: mixed (represented community declarations and local binary analysis).
// BSExtraDataStorageLayout, ExtraHealthStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraHealth.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x17ccd0 DeletingLeaf17ccd0::~DeletingLeaf17ccd0
void operator delete(void*, unsigned __int64) noexcept;
#include "ExtraHealthStorageLayout.h"
namespace ResearchLayouts {
inline BSExtraDataStorageLayout::~BSExtraDataStorageLayout() {}
inline ExtraHealthStorageLayout::~ExtraHealthStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::ExtraHealthStorageLayout) == 24, "independently observed allocation size");
static ResearchLayouts::ExtraHealthStorageLayout object;
