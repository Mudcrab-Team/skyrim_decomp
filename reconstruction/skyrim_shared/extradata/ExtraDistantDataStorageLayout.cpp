// Source exposure: mixed (represented community declarations and local binary analysis).
// BSExtraDataStorageLayout, ExtraDistantDataStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraDistantData.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x18f0d0 DeletingLeaf18f0d0::~DeletingLeaf18f0d0
void operator delete(void*, unsigned __int64) noexcept;
#include "ExtraDistantDataStorageLayout.h"
namespace ResearchLayouts {
inline BSExtraDataStorageLayout::~BSExtraDataStorageLayout() {}
inline ExtraDistantDataStorageLayout::~ExtraDistantDataStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::ExtraDistantDataStorageLayout) == 32, "independently observed allocation size");
static ResearchLayouts::ExtraDistantDataStorageLayout object;
