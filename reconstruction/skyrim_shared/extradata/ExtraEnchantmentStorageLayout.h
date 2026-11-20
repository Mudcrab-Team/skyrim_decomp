// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraEnchantment.h; MIT.
// ExtraEnchantment: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraEnchantmentLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ExtraEnchantmentLayout.h.
// ExtraEnchantmentStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataStorageLayout.h"

namespace ResearchLayouts {
class EnchantmentItem;
class ExtraEnchantmentStorageLayout : public BSExtraDataStorageLayout {
public:
    virtual ~ExtraEnchantmentStorageLayout();
    EnchantmentItem* enchantment;
    std::uint16_t charge;
    bool removeOnUnequip;
};
static_assert(sizeof(ExtraEnchantmentStorageLayout) == 32, "community represented size");
static_assert(offsetof(ExtraEnchantmentStorageLayout, enchantment) == 16, "enchantment offset");
static_assert(offsetof(ExtraEnchantmentStorageLayout, charge) == 24, "charge offset");
static_assert(offsetof(ExtraEnchantmentStorageLayout, removeOnUnequip) == 26, "removeOnUnequip offset");
}
