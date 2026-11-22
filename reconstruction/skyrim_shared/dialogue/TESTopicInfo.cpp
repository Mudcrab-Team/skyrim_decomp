// Source exposure: mixed (pinned image listing, labelled declarations and sibling reconstruction).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction with the labelled sibling adaptation.
// Adapted bodies: ResetSaidOnceFlags from the FNV sibling (CC0-1.0) with Skyrim field and API names.
// TESTopicInfo::ResetSaidOnceFlags: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/testopicinfo.cpp:919
// TESTopicInfo::ResetSaidOnceFlags, TESTopicInfo::DeleteFromTopic: CRASHLOGGER_PDB(59818@2026.10.24)
// RemoveTopicInfo, kSaidOnceChange: GUESS(low)
// 0x3f3150 TESTopicInfo::LoadGame
// 0x3f3180 TESTopicInfo::Revert
// 0x3f2620 TESTopicInfo::Function3f2620
// 0x3f2e60 TESTopicInfo::ResetSaidOnceFlags
// 0x3f2470 TESTopicInfo::DeleteFromTopic
#include "TESTopicInfo.h"

namespace {
constexpr std::uint32_t kSaidOnceChange = 0x80000000u;
}

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

// Clear the response's said-once state, including its persistent change flag.
void TESTopicInfo::ResetSaidOnceFlags()
{
    SetSaidOnceState(false);
    RemoveChange(kSaidOnceChange);
}

// Remove the response from the given topic.
void TESTopicInfo::DeleteFromTopic(TESTopic* a_topic)
{
    if (a_topic) {
        RemoveTopicInfo(a_topic, this);
    }
}
