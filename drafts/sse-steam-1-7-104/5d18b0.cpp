// Near miss: 73.83% | inline-set
// Exposure detail: (community declarations; pinned-image observations).
// Source exposure: mixed
// Code origin: original; target observations and labelled naming sources
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x5d18b0 MagicTarget::HasMagicEffectThatCausesDamage

#include "include/5d18b0/MagicTarget_5d18b0.h"

bool MagicTarget::HasMagicEffectThatCausesDamage()
{
    DamageVisitor visitor;
    auto* list = GetActiveEffectList();
    if (list && list->effect) {
        auto* node = list;
        std::uint32_t result = 0;
        while (node && result != 1) {
            result = visitor.Accept(node->effect);
            node = node->next;
        }
    }
    return visitor.found;
}
