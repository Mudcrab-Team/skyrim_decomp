// Source exposure: mixed (represented community declarations and local binary analysis).
// BSExtraDataStorageLayout, ExtraGhostStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraGhost.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x18f2e0 DeletingLeaf18f2e0::~DeletingLeaf18f2e0
void operator delete(void*, unsigned __int64) noexcept;
#include "ExtraGhostStorageLayout.h"
namespace ResearchLayouts {
inline BSExtraDataStorageLayout::~BSExtraDataStorageLayout() {}
inline ExtraGhostStorageLayout::~ExtraGhostStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::ExtraGhostStorageLayout) == 24, "independently observed allocation size");
static ResearchLayouts::ExtraGhostStorageLayout object;
