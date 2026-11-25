// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x4a6940 TESCondition::InitItem
// Adapted bodies: TESCondition::InitItem from fo4-private@1b765c70 src/Shared/AI/TESCondition.cpp:172 (see the header)
#include "TESCondition_4a6940.h"

void TESCondition::InitItem(TESForm* a_owner)
{
    for (TESConditionItem* item = head; item; item = item->next)
        item->InitItem(a_owner);
}
