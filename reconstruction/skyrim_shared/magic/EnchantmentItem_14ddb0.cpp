// Origin check: TestBit is independently written from cookbook rule 16; this incidental similarity is not reused.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
// Source exposure: mixed (community declarations, permitted sibling, local target).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// EnchantmentItem, MagicItem, EffectSetting: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TestBit: GUESS(low); bit-index flag accessor.
// EnchantmentItem::CanAddEffect, EnchantmentItem::EnchantmentItemFilterValidationFunction, MagicItem::HasEffect: SIBLING(fo4-private@1b765c70, author-permission)
// Code origin: body adapted from the cited permitted sibling filter; layout and accessors reconstructed locally.
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/EnchantmentItem.cpp:46
// 0x14ddb0 EnchantmentItem::CanAddEffect
#include "EnchantmentItem_14ddb0.h"

// Code origin: TestBit is an original by-value bit accessor following cookbook rule 16; the origin checker reports an incidental sibling similarity.
inline bool TestBit(std::uint32_t word, std::uint32_t bit)
{
    return ((word >> bit) & 1) != 0;
}

bool EnchantmentItem::CanAddEffect(EffectSetting* effect)
{
    if (effects.size != 0 &&
        EffectArchetypes::Archetypes[effect->data.archetype].associatedFormType != 0 &&
        TestBit(effect->data.flags, 18)) {
        return !HasEffect(0x40000);
    }
    return true;
}
