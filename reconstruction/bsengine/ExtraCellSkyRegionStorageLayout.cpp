// Source exposure: mixed (represented community declarations and local binary analysis).
// BSExtraDataStorageLayout, ExtraCellSkyRegionStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraCellSkyRegion.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x17c530 DeletingLeaf17c530::~DeletingLeaf17c530
void operator delete(void*, unsigned __int64) noexcept;
#include "ExtraCellSkyRegionStorageLayout.h"
namespace ResearchLayouts {
inline BSExtraDataStorageLayout::~BSExtraDataStorageLayout() {}
inline ExtraCellSkyRegionStorageLayout::~ExtraCellSkyRegionStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::ExtraCellSkyRegionStorageLayout) == 24, "independently observed allocation size");
static ResearchLayouts::ExtraCellSkyRegionStorageLayout object;
