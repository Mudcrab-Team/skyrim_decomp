// Source exposure: mixed (pinned image listing and labelled declarations).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image and labelled declarations.
// Adapted bodies: none for the newly submitted functions.
// TESTopicInfo::DeleteFromTopic: CRASHLOGGER_PDB(59818@2026.10.24)
// RemoveTopicInfo: GUESS(low)
// 0x3f3150 TESTopicInfo::LoadGame
// 0x3f3180 TESTopicInfo::Revert
// 0x3f2620 TESTopicInfo::Function3f2620
// 0x3f2470 TESTopicInfo::DeleteFromTopic
#include "TESTopicInfo.h"

void TESTopicInfo::LoadGame(BGSLoadFormBuffer* a_buf)
{
    TESForm::LoadGame(a_buf);
    if (static_cast<std::int32_t>(a_buf->changeFlags) < 0) {
        saidOnce = true;
    }
}

void TESTopicInfo::Revert(BGSLoadFormBuffer* a_buf)
{
    TESForm::Revert(a_buf);
    if (static_cast<std::int32_t>(a_buf->oldChangeFlags) < 0) {
        saidOnce = false;
    }
}
// Assign the response's index in the topic.
void TESTopicInfo::Function3f2620(std::uint16_t a_index)
{
    infoIndex = a_index;
}

// Remove the response from the given topic.
void TESTopicInfo::DeleteFromTopic(TESTopic* a_topic)
{
    if (a_topic) {
        RemoveTopicInfo(a_topic, this);
    }
}
