// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; target observations and labelled naming sources
// SPDX-License-Identifier: CC0-1.0
// 0x5d18b0 MagicTarget::HasMagicEffectThatCausesDamage
// Adapted bodies: none
#include "MagicTarget_5d18b0.h"

void MagicTarget::VisitEffects(DamageVisitor& visitor)
{
    EffectNode* node = GetActiveEffectList();
    // A non-empty list starts the walk; Accept returns 1 to keep going.
    std::uint32_t result = node && node->effect ? 1 : 0;
    while (node && result == 1) {
        result = visitor.Accept(node->effect);
        node = node->next;
    }
}

bool MagicTarget::HasMagicEffectThatCausesDamage()
{
    DamageVisitor visitor;
    VisitEffects(visitor);
    return visitor.found;
}
