// Source exposure: mixed (represented community declarations and local binary analysis).
// BSExtraDataStorageLayout, ExtraScaleStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraScale.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x17dab0 DeletingLeaf17dab0::~DeletingLeaf17dab0
void operator delete(void*, unsigned __int64) noexcept;
#include "ExtraScaleStorageLayout.h"
namespace ResearchLayouts {
inline BSExtraDataStorageLayout::~BSExtraDataStorageLayout() {}
inline ExtraScaleStorageLayout::~ExtraScaleStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::ExtraScaleStorageLayout) == 24, "independently observed allocation size");
static ResearchLayouts::ExtraScaleStorageLayout object;
