// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESTopic; size 0x60
// one of 2 different PDB types sharing this name
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "DIALOGUE_DATA.h"
#include "TESForm.h"
#include "TESFullName.h"
struct BGSDialogueBranch_10ee3dbc;
struct TESQuest_fe66f8e1;
struct TESTopicInfo_41161035;
struct TESTopic_3cb1295e {
    TESForm _base;
    TESFullName _base_TESFullName;
    DIALOGUE_DATA data;
    unsigned int priorityAndJournalIndex;
    BGSDialogueBranch_10ee3dbc* ownerBranch;
    TESQuest_fe66f8e1* ownerQuest;
    TESTopicInfo_41161035** topicInfos;
    unsigned int numTopicInfos;
    unsigned int firstFileOffset;
    BSFixedString_char_83b572b4 formEditorID;
};
static_assert(sizeof(TESTopic_3cb1295e) == 96, "TESTopic_3cb1295e layout differs from the PDB");
