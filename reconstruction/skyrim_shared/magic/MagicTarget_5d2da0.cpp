// Source exposure: mixed (community naming and local pinned-image observations).
// Code origin: original; no sibling body reused
// SPDX-License-Identifier: CC0-1.0
// 0x5d2da0 MagicTarget::FindFirstEffectWithArchetype
// Adapted bodies: none
#include "MagicTarget_5d2da0.h"

// IsBitClear: GUESS(low); flag-word clear-bit test taking the word and bit index by value (cookbook rule 16).
inline bool IsBitClear(std::uint32_t word, std::uint32_t bit)
{
    return (~(word >> bit) & 1) != 0;
}

ActiveEffect* MagicTarget::FindFirstEffectWithArchetype(std::uint32_t archetype, bool includeInactive)
{
    EffectListNode* node = GetActiveEffects();
    ActiveEffect* result = nullptr;
    for (; node && !result; node = node->next) {
        ActiveEffect* effect = node->effect;
        if (effect && effect->GetBaseObject()->archetype == archetype &&
            (includeInactive || IsBitClear(effect->flags, 15))) {
            result = effect;
        }
    }
    return result;
}
