// Near miss: 83.22% | inline-set
// Exposure detail: (community naming and local pinned-image observations).
// Source exposure: mixed
// Code origin: original; no sibling body reused
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x5d2da0 MagicTarget::FindFirstEffectWithArchetype

#include "include/5d2da0/MagicTarget_5d2da0.h"

ActiveEffect* MagicTarget::FindFirstEffectWithArchetype(std::uint32_t archetype, bool includeInactive)
{
    EffectListNode* node = GetActiveEffects();
    ActiveEffect* result = nullptr;
    if (node) {
        do {
            if (result)
                break;
            ActiveEffect* effect = node->effect;
            if (effect && effect->GetBaseObject()->archetype == archetype &&
                (includeInactive || !(effect->flags & 1))) {
                result = effect;
            }
            node = node->next;
        } while (node);
    }
    return result;
}
