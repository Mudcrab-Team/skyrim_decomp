// Source exposure: mixed (represented community declarations and local binary analysis).
// BSExtraDataStorageLayout, ExtraAlphaCutoffStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraAlphaCutoff.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x17c220 DeletingLeaf17c220::~DeletingLeaf17c220
void operator delete(void*, unsigned __int64) noexcept;
#include "ExtraAlphaCutoffStorageLayout.h"
namespace ResearchLayouts {
inline BSExtraDataStorageLayout::~BSExtraDataStorageLayout() {}
inline ExtraAlphaCutoffStorageLayout::~ExtraAlphaCutoffStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::ExtraAlphaCutoffStorageLayout) == 24, "independently observed allocation size");
static ResearchLayouts::ExtraAlphaCutoffStorageLayout object;
