// Source exposure: mixed (pinned image listing and labelled declarations).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing with labelled declarations. Stamped as a twin of matched 0x38cf10 (skyrim_shared/dialogue/BGSDialogueBranch): source copied, names replaced by placeholders.
// 0x160ac30 Owner160ac30::Function160ac30
#include "Owner160ac30.h"

// Assign the dialogue branch's starting topic.
void Owner160ac30::Function160ac30(TESTopic* a_topic)
{
    startingTopic = a_topic;
}
