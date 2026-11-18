// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraEnchantment.h; MIT.
// ExtraEnchantment: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraEnchantmentLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/BSExtraDataLayout.h"

namespace ResearchLayouts {
class EnchantmentItem;
class ExtraEnchantmentLayout : public BSExtraDataLayout {
public:
    virtual ~ExtraEnchantmentLayout();
    EnchantmentItem* enchantment;
    std::uint16_t charge;
    bool removeOnUnequip;
};
static_assert(sizeof(ExtraEnchantmentLayout) == 32, "community represented size");
static_assert(offsetof(ExtraEnchantmentLayout, enchantment) == 16, "enchantment offset");
static_assert(offsetof(ExtraEnchantmentLayout, charge) == 24, "charge offset");
static_assert(offsetof(ExtraEnchantmentLayout, removeOnUnequip) == 26, "removeOnUnequip offset");
}
