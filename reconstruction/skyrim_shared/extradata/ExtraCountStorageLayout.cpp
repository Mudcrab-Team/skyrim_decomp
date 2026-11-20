// Source exposure: mixed (represented community declarations and local binary analysis).
// BSExtraDataStorageLayout, ExtraCountStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraCount.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x17c680 DeletingLeaf17c680::~DeletingLeaf17c680
void operator delete(void*, unsigned __int64) noexcept;
#include "ExtraCountStorageLayout.h"
namespace ResearchLayouts {
inline BSExtraDataStorageLayout::~BSExtraDataStorageLayout() {}
inline ExtraCountStorageLayout::~ExtraCountStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::ExtraCountStorageLayout) == 24, "independently observed allocation size");
static ResearchLayouts::ExtraCountStorageLayout object;
