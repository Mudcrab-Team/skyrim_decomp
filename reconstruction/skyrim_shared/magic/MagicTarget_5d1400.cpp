// Source exposure: mixed (pinned-image observations; community declarations; permitted sibling algorithm lead).
// Code origin: original; target observations and labelled declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x5d1400 MagicTarget::DispelAllSpells_140552E10
// Adapted bodies: none
#include "MagicTarget_5d1400.h"

// The list walk takes the visitor by base reference, so each Accept stays a virtual call.
static void VisitEffects(EffectNode* node, EffectVisitor& visitor)
{
    std::uint32_t result = node && node->item ? 1 : 0;
    while (node && result == 1) {
        result = visitor.Accept(node->item);
        node = node->next;
    }
}

void MagicTarget::DispelAllSpells_140552E10(bool now)
{
    DispelVisitor visitor(now);
    VisitEffects(GetActiveEffectList(), visitor);
}
