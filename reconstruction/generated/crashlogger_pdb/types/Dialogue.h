// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Dialogue; size 0x58
#pragma once

#include "BSSimpleList_RE__DialogueResponse_eb2198ba.h"
#include "BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce.h"
struct Node_dfb14146;
struct TESQuest_fe66f8e1;
struct TESTopicInfo_41161035;
struct TESTopic_3cb1295e;
struct Dialogue {
    BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce topicText;
    bool unk10;
    bool unk11;
    bool unk12;
    unsigned char unk13;
    unsigned int unk14;
    BSSimpleList_RE__DialogueResponse_eb2198ba responses;
    TESQuest_fe66f8e1* parentQuest;
    TESTopicInfo_41161035* parentTopicInfo;
    TESTopic_3cb1295e* parentTopic;
    Node_dfb14146* currentResponse;
    unsigned char unk48;
    bool neverSaid;
    unsigned short unk4A;
    unsigned int unk4C;
    TESTopic_3cb1295e* unk50;
};
static_assert(sizeof(Dialogue) == 88, "Dialogue layout differs from the PDB");
