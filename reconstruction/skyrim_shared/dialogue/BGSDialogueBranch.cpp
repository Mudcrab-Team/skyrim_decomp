// Source exposure: mixed (pinned image listing and labelled declarations).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing with labelled declarations.
// Adapted bodies: none.
// 0x38cac0 BGSDialogueBranch::InitializeData
// 0x38cf10 BGSDialogueBranch::Function38cf10
#include "BGSDialogueBranch.h"

void BGSDialogueBranch::InitializeData()
{
    flags = 1;
    quest = nullptr;
    startingTopic = nullptr;
}
// Assign the dialogue branch's starting topic.
void BGSDialogueBranch::Function38cf10(TESTopic* a_topic)
{
    startingTopic = a_topic;
}
