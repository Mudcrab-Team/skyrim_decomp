// Source exposure: binary-analysis (pinned image listing).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: TESCondition4a6d90::ClearAllConditions, treated as adapted: shaped like TESCondition::~TESCondition (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/T/TESCondition.cpp:57, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x4a6d90 TESCondition4a6d90::ClearAllConditions
#include "TESCondition4a6d90.h"

// Deletes every item in the condition list, advancing head before each delete.
void TESCondition4a6d90::ClearAllConditions()
{
    while (head != nullptr) {
        ConditionItem4a6d90* item = head;
        head = item->next;
        delete item;
    }
}
