// Source exposure: mixed (represented community declarations and local binary analysis).
// BSExtraDataStorageLayout, ExtraObjectHealthStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraObjectHealth.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x17d3b0 DeletingLeaf17d3b0::~DeletingLeaf17d3b0
void operator delete(void*, unsigned __int64) noexcept;
#include "ExtraObjectHealthStorageLayout.h"
namespace ResearchLayouts {
inline BSExtraDataStorageLayout::~BSExtraDataStorageLayout() {}
inline ExtraObjectHealthStorageLayout::~ExtraObjectHealthStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::ExtraObjectHealthStorageLayout) == 24, "independently observed allocation size");
static ResearchLayouts::ExtraObjectHealthStorageLayout object;
