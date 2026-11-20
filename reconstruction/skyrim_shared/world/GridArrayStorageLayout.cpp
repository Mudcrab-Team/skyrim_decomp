// Source exposure: mixed (represented community declarations and local binary analysis).
// GridArrayStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/G/GridArray.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x226f70 DeletingLeaf226f70::~DeletingLeaf226f70
void operator delete(void*, unsigned __int64) noexcept;
#include "GridArrayStorageLayout.h"
namespace ResearchLayouts {
inline GridArrayStorageLayout::~GridArrayStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::GridArrayStorageLayout) == 24, "independently observed allocation size");
static ResearchLayouts::GridArrayStorageLayout object;
