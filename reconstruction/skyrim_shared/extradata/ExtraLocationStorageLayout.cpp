// Source exposure: mixed (represented community declarations and local binary analysis).
// BSExtraDataStorageLayout, ExtraLocationStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraLocation.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x17d0e0 DeletingLeaf17d0e0::~DeletingLeaf17d0e0
void operator delete(void*, unsigned __int64) noexcept;
#include "ExtraLocationStorageLayout.h"
namespace ResearchLayouts {
inline BSExtraDataStorageLayout::~BSExtraDataStorageLayout() {}
inline ExtraLocationStorageLayout::~ExtraLocationStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::ExtraLocationStorageLayout) == 24, "independently observed allocation size");
static ResearchLayouts::ExtraLocationStorageLayout object;
