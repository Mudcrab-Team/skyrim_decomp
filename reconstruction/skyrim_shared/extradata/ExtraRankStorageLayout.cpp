// Source exposure: mixed (represented community declarations and local binary analysis).
// BSExtraDataStorageLayout, ExtraRankStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraRank.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x17d790 DeletingLeaf17d790::~DeletingLeaf17d790
void operator delete(void*, unsigned __int64) noexcept;
#include "ExtraRankStorageLayout.h"
namespace ResearchLayouts {
inline BSExtraDataStorageLayout::~BSExtraDataStorageLayout() {}
inline ExtraRankStorageLayout::~ExtraRankStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::ExtraRankStorageLayout) == 24, "independently observed allocation size");
static ResearchLayouts::ExtraRankStorageLayout object;
