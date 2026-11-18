// Source exposure: mixed (represented community declarations and local binary analysis).
// BSExtraDataStorageLayout, ExtraCannotWearStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraCannotWear.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x17c400 DeletingLeaf17c400::~DeletingLeaf17c400
void operator delete(void*, unsigned __int64) noexcept;
#include "ExtraCannotWearStorageLayout.h"
namespace ResearchLayouts {
inline BSExtraDataStorageLayout::~BSExtraDataStorageLayout() {}
inline ExtraCannotWearStorageLayout::~ExtraCannotWearStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::ExtraCannotWearStorageLayout) == 16, "independently observed allocation size");
static ResearchLayouts::ExtraCannotWearStorageLayout object;
