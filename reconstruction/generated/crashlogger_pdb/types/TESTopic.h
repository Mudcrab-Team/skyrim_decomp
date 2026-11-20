// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESTopic; size 0x60
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString.h"
#include "TESFileContainer_70f0bdf4.h"
#include "TESTopic__Data.h"
struct BGSDialogueBranch;
struct TESFullName__VFTable;
struct TESQuest;
struct TESTopicInfo;
struct TESTopic__VFTable;
struct TESTopic {
    TESTopic__VFTable* vftable_TESTopic_0;
    TESFileContainer_70f0bdf4 FormSourceFiles_8;
    unsigned int FormFlags_10;
    unsigned int FormId_14;
    unsigned short FormGameFlags_18;
    unsigned char FormType_1A;
    char _pad_1B[5];
    TESFullName__VFTable* vftable_TESFullName_20;
    BSFixedString Text_28;
    TESTopic__Data TopicData_30;
    int PriorityAndJournalIndex_34;
    BGSDialogueBranch* OwnerBranch_38;
    TESQuest* OwnerQuest_40;
    TESTopicInfo** TopicInfos_48;
    int NumTopicInfos_50;
    unsigned int FirstFileOffset_54;
    BSFixedString FormEditorId_58;
};
static_assert(sizeof(TESTopic) == 96, "TESTopic layout differs from the PDB");
