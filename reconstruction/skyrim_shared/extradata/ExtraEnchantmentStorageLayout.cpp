// Source exposure: mixed (represented community declarations and local binary analysis).
// BSExtraDataStorageLayout, ExtraEnchantmentStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraEnchantment.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x17c860 DeletingLeaf17c860::~DeletingLeaf17c860
void operator delete(void*, unsigned __int64) noexcept;
#include "ExtraEnchantmentStorageLayout.h"
namespace ResearchLayouts {
inline BSExtraDataStorageLayout::~BSExtraDataStorageLayout() {}
inline ExtraEnchantmentStorageLayout::~ExtraEnchantmentStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::ExtraEnchantmentStorageLayout) == 32, "independently observed allocation size");
static ResearchLayouts::ExtraEnchantmentStorageLayout object;
