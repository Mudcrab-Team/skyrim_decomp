// Source exposure: mixed (represented community declarations and local binary analysis).
// BSExtraDataStorageLayout, ExtraTeleportNameStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraTeleportName.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x17dc90 DeletingLeaf17dc90::~DeletingLeaf17dc90
void operator delete(void*, unsigned __int64) noexcept;
#include "ExtraTeleportNameStorageLayout.h"
namespace ResearchLayouts {
inline BSExtraDataStorageLayout::~BSExtraDataStorageLayout() {}
inline ExtraTeleportNameStorageLayout::~ExtraTeleportNameStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::ExtraTeleportNameStorageLayout) == 24, "independently observed allocation size");
static ResearchLayouts::ExtraTeleportNameStorageLayout object;
