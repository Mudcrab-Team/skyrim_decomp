// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Function4a6810, treated as adapted: shaped like TESCondition::~TESCondition (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/T/TESCondition.cpp:57, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x4a6810 Function4a6810
#include "FreeFunction_4a6810.h"

// Deletes every node in the singly linked condition list, advancing head before each delete.
void Function4a6810(ConditionList4a6810* list)
{
    while (list->head != nullptr) {
        ConditionNode4a6810* node = list->head;
        list->head = node->next;
        delete node;
    }
}
