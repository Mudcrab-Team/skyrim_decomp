// Source exposure: mixed (pinned image listing and labelled community declarations).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing and labelled declarations.
// Adapted bodies: none.
// TESQuest::FindStage, TESQuest::executedStages: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x3dfeb0 TESQuest::QConditions
// 0x3df9b0 TESQuest::GetFormEditorID
// 0x3d2870 TESQuest::FinishLoadGame
// 0x3ce410 TESQuest::InitializeData
// 0x3dedb0 TESQuest::~TESQuest
// 0x3d1b00 TESQuest::FindStage
#include "TESQuest.h"

// Find a stage by index in the quest's executed stage list.
TESQuestStage* TESQuest::FindStage(std::uint16_t a_index) const
{
    for (auto* entry = &executedStages; entry; entry = entry->next) {
        TESQuestStage* stage = entry->stage;
        if (stage && stage->data.index == a_index) {
            return stage;
        }
    }
    return nullptr;
}

// Not compared: defined so that this unit emits the vftable and with it the deleting destructor.
TESQuest::TESQuest()
{
}

TESCondition* TESQuest::QConditions()
{
    return &objConditions;
}

const char* TESQuest::GetFormEditorID() const
{
    return formEditorID.c_str();
}

void TESQuest::FinishLoadGame(BGSLoadFormBuffer* a_buf)
{
    TESForm::FinishLoadGame(a_buf);
    if (promoteTask) {
        promoteTask->Finish();
    }
}

void TESQuest::InitializeData()
{
    eventID = 0xFFFFFFFF;
    data.flags |= static_cast<std::uint16_t>(QuestFlag::kRunOnce);
    currentStage = 0;
    startEventData = nullptr;
    currentInstanceID = 0;
    alreadyRun = false;
}
