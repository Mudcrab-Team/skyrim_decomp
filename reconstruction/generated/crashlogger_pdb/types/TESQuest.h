// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESQuest; size 0x268
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString.h"
#include "BSSimpleList_BGSQuestObjective_1b292fd6.h"
#include "BSString.h"
#include "BSTArray_BGSBaseAlias_64f9d630.h"
#include "BSTArray_BGSQuestInstanceText_ad4205cc.h"
#include "BSTArray_BGSScene_065561f4.h"
#include "BSTArray_TESTopic_17df7471.h"
#include "BSTArray_uint32.h"
#include "BSTHashMap_BGSDialogueBranch__BSTArray_TESTopic.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_4c05441a.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_long_long_std__equal_to_unsigned_long_long_RE__BST_7fe24860.h"
#include "MutexRW.h"
#include "NiPointer_QueuedPromoteQuestTask_fc04a943.h"
#include "QuestEvent.h"
#include "TESCondition.h"
#include "TESFileContainer_70f0bdf4.h"
#include "TESQuest__Data.h"
struct BGSStoryEvent;
struct BSSimpleList_TESQuest__StageData;
struct BSSimpleList_TESQuest__StageData_2ea53ed5;
struct BSTArray_TESGlobal_35c7abf4;
struct TESFullName__VFTable;
struct TESQuest__VFTable;
struct TESQuest {
    TESQuest__VFTable* vftable_TESQuest_0;
    TESFileContainer_70f0bdf4 FormSourceFiles_8;
    unsigned int FormFlags_10;
    unsigned int FormId_14;
    unsigned short FormGameFlags_18;
    unsigned char FormType_1A;
    char _pad_1B[5];
    unsigned int LastVisitorId_20;
    char _pad_24[4];
    TESFullName__VFTable* vftable_TESFullName_28;
    BSFixedString Text_30;
    BSTArray_BGSQuestInstanceText_ad4205cc InstanceData_38;
    unsigned int currentInstanceID;
    unsigned int pad054;
    BSTArray_BGSBaseAlias_64f9d630 Aliases_58;
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_4c05441a refAliasMap;
    BSTScatterTable_RE__BSCRC32_unsigned_long_long_std__equal_to_unsigned_long_long_RE__BST_7fe24860 unk0A0;
    MutexRW AliasAccessLock_D0;
    TESQuest__Data QuestData_D8;
    QuestEvent eventID;
    unsigned int pad0E4;
    BSSimpleList_TESQuest__StageData* ExecutedStages_E8;
    BSSimpleList_TESQuest__StageData_2ea53ed5* WaitingStages_F0;
    BSSimpleList_BGSQuestObjective_1b292fd6 Objectives_F8;
    TESCondition ObjectiveConditions_108;
    TESCondition StoryManagerConditions_110;
    BSTHashMap_BGSDialogueBranch__BSTArray_TESTopic BranchedDialogue_118[2];
    BSTArray_TESTopic_17df7471 Topics_178[6];
    BSTArray_BGSScene_065561f4 Scenes_208;
    BSTArray_TESGlobal_35c7abf4* TextGlobals_220;
    unsigned short currentStage;
    bool AlreadyRun_22A;
    unsigned char pad22B;
    unsigned int pad22C;
    BSString FormEditorId_230;
    BGSStoryEvent* StartEventData_240;
    NiPointer_QueuedPromoteQuestTask_fc04a943 PromoteTask_248;
    BSTArray_uint32 PromotedRefHandles_250;
};
static_assert(sizeof(TESQuest) == 616, "TESQuest layout differs from the PDB");
