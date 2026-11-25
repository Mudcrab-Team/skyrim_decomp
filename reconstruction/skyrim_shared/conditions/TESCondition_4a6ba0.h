// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/AI/TESCondition.cpp:210
// TESCondition, TESCondition::Compare, TESConditionItem::Compare: SIBLING(fo4-private@1b765c70, author-permission)
// TESCondition::head, TESConditionItem, TESConditionItem::next: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>

struct TESConditionItem
{
    bool Compare(const TESConditionItem* a_other) const;

    TESConditionItem* next;  // 00
};

class TESCondition
{
public:
    bool Compare(const TESCondition* a_other) const;

    TESConditionItem* head;  // 00
};
static_assert(sizeof(TESCondition) == 0x8, "TESCondition size");
