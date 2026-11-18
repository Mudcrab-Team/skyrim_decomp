// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// Bodies adapted from community sources: none; tools/check_origin.py reports none above its threshold.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x3dfeb0 TESQuest::QConditions
// 0x3df9b0 TESQuest::GetFormEditorID
// 0x3d2870 TESQuest::FinishLoadGame
// 0x3ce410 TESQuest::InitializeData
// 0x3dedb0 TESQuest::~TESQuest
#include "TESQuest.h"

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
