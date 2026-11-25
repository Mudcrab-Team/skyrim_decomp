// Source exposure: mixed (community declarations, permitted sibling, local target).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// EnchantmentItem::InitializeData, MagicItem::InitializeData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/EnchantmentItem.cpp:25
// Code origin: body adapted from the cited permitted sibling initialization; member layout reconstructed locally.
// 0x14dba0 EnchantmentItem::InitializeData
#include "EnchantmentItem_14dba0.h"

void EnchantmentItem::InitializeData()
{
    data.costOverride = -1;
    data.chargeOverride = -1;
    data.spellType = MagicSystem::SpellType::kEnchantment;
    data.castingType = MagicSystem::CastingType::kScroll;
    data.delivery = MagicSystem::Delivery::kTotal;
    data.flags = 0;
    data.chargeTime = 0.0f;
    data.baseEnchantment = nullptr;
    data.wornRestrictions = nullptr;
    MagicItem::InitializeData();
}
