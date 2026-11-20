// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DialogueItem; size 0x48
// one of 2 different PDB types sharing this name
#pragma once

#include "BSSimpleList_DialogueResponse_62b08a87.h"
struct Actor;
struct ExtraSayToTopicInfo;
struct TESQuest;
struct TESTopic;
struct TESTopicInfo;
struct DialogueItem_6f899a07 {
    int refCount_0;
    char _pad_4[4];
    BSSimpleList_DialogueResponse_62b08a87 Responses_8;
    BSSimpleList_DialogueResponse_62b08a87* CurrentResponse_18;
    TESTopicInfo* TopicInfo_20;
    TESTopic* Topic_28;
    TESQuest* Quest_30;
    Actor* Speaker_38;
    ExtraSayToTopicInfo* ExtraData_40;
};
static_assert(sizeof(DialogueItem_6f899a07) == 72, "DialogueItem_6f899a07 layout differs from the PDB");
