// Near miss: 3.0 alignment distance | control-flow
// Exposure detail: (community declarations, permitted sibling, local target).
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// EnchantmentItem, MagicItem, EffectSetting: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TestBit: GUESS(low); bit-index flag accessor.
// EnchantmentItem::CanAddEffect, EnchantmentItem::EnchantmentItemFilterValidationFunction, MagicItem::HasEffect: SIBLING(fo4-private@1b765c70, author-permission)
// Code origin: body adapted from the cited permitted sibling filter; layout and accessors reconstructed locally.
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/EnchantmentItem.cpp:59
// 0x14dfe0 EnchantmentItem::EnchantmentItemFilterValidationFunction

#include "include/14dfe0/EnchantmentItem_14dfe0.h"

// EffectArchetypes::GetAssociatedFormType: SIBLING(fo4-private@1b765c70, author-permission)
// Code origin: original table accessor for the locally observed table layout.
inline std::int32_t EffectArchetypes::GetAssociatedFormType(std::int32_t archetype)
{
    return Archetypes[archetype].associatedFormType;
}

// Code origin: TestBit is an original by-value bit accessor following cookbook rule 16; the origin checker reports an incidental sibling similarity.
inline bool TestBit(std::uint32_t word, std::uint32_t bit)
{
    return ((word >> bit) & 1) != 0;
}

bool EnchantmentItem::EnchantmentItemFilterValidationFunction(EffectSetting* effect, void* validationItem)
{
    MagicItem* item = static_cast<MagicItem*>(validationItem);
    if (item->effects.size) {
        if (EffectArchetypes::GetAssociatedFormType(effect->data.archetype) != 0) {
            bool bFlag = TestBit(effect->data.flags, 18);
            if (bFlag) {
                return !item->HasEffect(0x40000);
            }
        }
    }
    return true;
}
