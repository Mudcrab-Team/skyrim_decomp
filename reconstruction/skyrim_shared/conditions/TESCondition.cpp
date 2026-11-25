// Source exposure: mixed (community headers; the pinned image listing); mixed (community headers, the pinned image listing, and a permitted private sibling for IsTrue)
// Origin: independently decoded target, anonymous sibling and public declarations.
// Code origin: Function4a6c10 and Function4a6df0 are original reconstructions from the listing.
// Adapted bodies: TESCondition::IsTrue from fo4-private@1b765c70 src/Shared/AI/TESCondition.cpp:349 (author-permission)
// 0x4a6df0 TESCondition::Function4a6df0
// 0x4a6c10 TESCondition::Function4a6c10
// TESCondition::IsTrue: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/AI/TESCondition.cpp:349
// ConditionCheckParams: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declaration adapted from include/RE/T/TESCondition.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Drafted by v-macrev, assisted by claude-sonnet-5-5.
#include "TESCondition.h"
bool TESCondition::IsTrue(TESObjectREFR* action, TESObjectREFR* target) const { ConditionCheckParams params{action, target, nullptr, nullptr, nullptr, false, nullptr}; ConditionItemIsTrue checker; return IsTrue(params, checker); }

void TESCondition::Function4a6df0()
{
    ConditionNode* node = head;
    while (node) {
        ConditionNode* next = node->next;
        if (!next) {
            node->flag30 &= static_cast<std::uint8_t>(~1u);
        }
        node = next;
    }
}

void TESCondition::Function4a6c10(ConditionNode* newNode)
{
    ConditionNode** link = &head;
    while (*link) {
        link = &(*link)->next;
    }
    *link = newNode;
}
