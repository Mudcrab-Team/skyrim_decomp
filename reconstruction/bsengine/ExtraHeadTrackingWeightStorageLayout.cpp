// Source exposure: mixed (represented community declarations and local binary analysis).
// BSExtraDataStorageLayout, ExtraHeadTrackingWeightStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraHeadTrackingWeight.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x17cc70 DeletingLeaf17cc70::~DeletingLeaf17cc70
void operator delete(void*, unsigned __int64) noexcept;
#include "ExtraHeadTrackingWeightStorageLayout.h"
namespace ResearchLayouts {
inline BSExtraDataStorageLayout::~BSExtraDataStorageLayout() {}
inline ExtraHeadTrackingWeightStorageLayout::~ExtraHeadTrackingWeightStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::ExtraHeadTrackingWeightStorageLayout) == 24, "independently observed allocation size");
static ResearchLayouts::ExtraHeadTrackingWeightStorageLayout object;
