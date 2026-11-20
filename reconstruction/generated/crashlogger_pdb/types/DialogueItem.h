// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DialogueItem; size 0x48
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSIntrusiveRefCounted.h"
#include "BSSimpleList_RE__DialogueResponse_eb2198ba.h"
struct ExtraSayToTopicInfo_5e2c538b;
struct Node_dfb14146;
struct TESObjectREFR_b225f218;
struct TESQuest_fe66f8e1;
struct TESTopicInfo_41161035;
struct TESTopic_3cb1295e;
struct DialogueItem {
    BSIntrusiveRefCounted _base;
    unsigned int pad04;
    BSSimpleList_RE__DialogueResponse_eb2198ba responses;
    Node_dfb14146* currentResponse;
    TESTopicInfo_41161035* info;
    TESTopic_3cb1295e* topic;
    TESQuest_fe66f8e1* quest;
    TESObjectREFR_b225f218* speaker;
    ExtraSayToTopicInfo_5e2c538b* extraData;
};
static_assert(sizeof(DialogueItem) == 72, "DialogueItem layout differs from the PDB");
