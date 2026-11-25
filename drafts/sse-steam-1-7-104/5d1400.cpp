// Near miss: 48.51% | inline-set
// Exposure detail: (pinned-image observations; community declarations; permitted sibling algorithm lead).
// Source exposure: mixed
// Code origin: original; target observations and labelled declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x5d1400 MagicTarget::DispelAllSpells_140552E10

#include "include/5d1400/MagicTarget_5d1400.h"

void MagicTarget::DispelAllSpells_140552E10(bool now)
{
    DispelVisitor visitor{ &dispelVisitorTable, now };
    EffectNode* node = GetActiveEffectList();
    if (!node || !node->item) {
        return;
    }
    std::uint32_t result = 1;
    do {
        if (result != 1) {
            break;
        }
        result = visitor.vptr->Accept(&visitor, node->item);
        node = node->next;
    } while (node);
}
