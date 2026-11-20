// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESQuest; size 0x268
// one of 2 different PDB types sharing this name
#pragma once

#include "BGSStoryManagerTreeForm.h"
#include "BSReadWriteLock.h"
#include "BSSimpleList_RE__BGSQuestObjective_b54cca2a.h"
#include "BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce.h"
#include "BSTArray_RE__BGSBaseAlias_80b324d9.h"
#include "BSTArray_RE__BGSQuestInstanceText_59682b56.h"
#include "BSTArray_RE__BGSScene_4b30de10.h"
#include "BSTArray_RE__BSPointerHandle_RE__TESObjectREFR_a12b1937_f051e2e8.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_4c05441a.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_long_long_std__equal_to_unsigned_long_long_RE__BST_7fe24860.h"
#include "NiPointer_RE__QueuedPromoteQuestTask_d756c470.h"
#include "QUEST_DATA.h"
#include "QuestEvent.h"
#include "TESCondition_4d3cdc88.h"
#include "TESFullName.h"
struct BGSStoryEvent;
struct RE__BSSimpleList_RE__TESQuestStage_4c65cf3a;
struct RE__BSSimpleList_RE__TESQuestStage_fde8255d;
struct RE__BSTArray_RE__TESGlobal_55270642;
struct TESQuest_fe66f8e1 {
    BGSStoryManagerTreeForm _base;
    TESFullName _base_TESFullName;
    BSTArray_RE__BGSQuestInstanceText_59682b56 instanceData;
    unsigned int currentInstanceID;
    unsigned int pad054;
    BSTArray_RE__BGSBaseAlias_80b324d9 aliases;
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_4c05441a refAliasMap;
    BSTScatterTable_RE__BSCRC32_unsigned_long_long_std__equal_to_unsigned_long_long_RE__BST_7fe24860 unk0A0;
    BSReadWriteLock aliasAccessLock;
    QUEST_DATA data;
    QuestEvent eventID;
    unsigned int pad0E4;
    RE__BSSimpleList_RE__TESQuestStage_4c65cf3a* executedStages;
    RE__BSSimpleList_RE__TESQuestStage_fde8255d* waitingStages;
    BSSimpleList_RE__BGSQuestObjective_b54cca2a objectives;
    TESCondition_4d3cdc88 objConditions;
    TESCondition_4d3cdc88 storyManagerConditions;
    unsigned char branchedDialogue_raw[96];
    unsigned char topics_raw[144];
    BSTArray_RE__BGSScene_4b30de10 scenes;
    RE__BSTArray_RE__TESGlobal_55270642* textGlobals;
    unsigned short currentStage;
    bool alreadyRun;
    unsigned char pad22B;
    unsigned int pad22C;
    BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce formEditorID;
    BGSStoryEvent* startEventData;
    NiPointer_RE__QueuedPromoteQuestTask_d756c470 promoteTask;
    BSTArray_RE__BSPointerHandle_RE__TESObjectREFR_a12b1937_f051e2e8 promotedRefs;
};
static_assert(sizeof(TESQuest_fe66f8e1) == 616, "TESQuest_fe66f8e1 layout differs from the PDB");
