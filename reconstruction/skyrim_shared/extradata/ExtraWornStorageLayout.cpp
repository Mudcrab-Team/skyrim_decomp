// Source exposure: mixed (represented community declarations and local binary analysis).
// BSExtraDataStorageLayout, ExtraWornStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraWorn.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x17df10 DeletingLeaf17df10::~DeletingLeaf17df10
void operator delete(void*, unsigned __int64) noexcept;
#include "ExtraWornStorageLayout.h"
namespace ResearchLayouts {
inline BSExtraDataStorageLayout::~BSExtraDataStorageLayout() {}
inline ExtraWornStorageLayout::~ExtraWornStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::ExtraWornStorageLayout) == 16, "independently observed allocation size");
static ResearchLayouts::ExtraWornStorageLayout object;
