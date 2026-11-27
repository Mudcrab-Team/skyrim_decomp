// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/AI/TESCondition.cpp:172
// TESCondition, TESCondition::InitItem: SIBLING(fo4-private@1b765c70, author-permission)
// TESConditionItem::InitItem: GUESS(medium); name from the sibling call site
// TESCondition::head, TESConditionItem, TESConditionItem::next, TESForm: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>

class TESForm;

struct TESConditionItem
{
    void InitItem(TESForm* a_owner);

    TESConditionItem* next;  // 00
};

class TESCondition
{
public:
    void InitItem(TESForm* a_owner);

    TESConditionItem* head;  // 00
};
static_assert(sizeof(TESCondition) == 0x8, "TESCondition size");
