// Source exposure: mixed (represented community declarations and local binary analysis).
// BSExtraDataStorageLayout, ExtraChargeStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraCharge.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x17c5e0 DeletingLeaf17c5e0::~DeletingLeaf17c5e0
void operator delete(void*, unsigned __int64) noexcept;
#include "ExtraChargeStorageLayout.h"
namespace ResearchLayouts {
inline BSExtraDataStorageLayout::~BSExtraDataStorageLayout() {}
inline ExtraChargeStorageLayout::~ExtraChargeStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::ExtraChargeStorageLayout) == 24, "independently observed allocation size");
static ResearchLayouts::ExtraChargeStorageLayout object;
