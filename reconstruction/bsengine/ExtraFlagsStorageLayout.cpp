// Source exposure: mixed (represented community declarations and local binary analysis).
// BSExtraDataStorageLayout, ExtraFlagsStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraFlags.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x17c970 DeletingLeaf17c970::~DeletingLeaf17c970
void operator delete(void*, unsigned __int64) noexcept;
#include "ExtraFlagsStorageLayout.h"
namespace ResearchLayouts {
inline BSExtraDataStorageLayout::~BSExtraDataStorageLayout() {}
inline ExtraFlagsStorageLayout::~ExtraFlagsStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::ExtraFlagsStorageLayout) == 24, "independently observed allocation size");
static ResearchLayouts::ExtraFlagsStorageLayout object;
