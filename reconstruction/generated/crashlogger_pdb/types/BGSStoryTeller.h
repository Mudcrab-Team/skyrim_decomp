// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSStoryTeller; size 0xd8
#pragma once

#include "BSTArray_RE__TESQuest_d778905a_75e5810a.h"
#include "BSTEventSink_RE__TESQuestStageItemDoneEvent_71317dca.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_42d4d83f.h"
#include "BSTSingletonSDM_RE__BGSStoryTeller_c7043665.h"
struct BGSStoryTeller {
    BSTEventSink_RE__TESQuestStageItemDoneEvent_71317dca _base;
    BSTSingletonSDM_RE__BGSStoryTeller_c7043665 _base_BSTSingletonSDM_RE_BGSStoryTeller_;
    unsigned char pad09;
    unsigned short pad0A;
    unsigned int pad0C;
    BSTArray_RE__TESQuest_d778905a_75e5810a queuedStartQuests;
    BSTArray_RE__TESQuest_d778905a_75e5810a runningQuests;
    BSTArray_RE__TESQuest_d778905a_75e5810a queuedStopQuests;
    BSTArray_RE__TESQuest_d778905a_75e5810a infoClearQuests;
    BSTArray_RE__TESQuest_d778905a_75e5810a helloTopicQuests;
    BSTArray_RE__TESQuest_d778905a_75e5810a greetingTopicQuests;
    bool startUpQuestsInitialized;
    unsigned char padA1;
    unsigned short padA2;
    unsigned int padA4;
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_42d4d83f questStageWaitMap;
};
static_assert(sizeof(BGSStoryTeller) == 216, "BGSStoryTeller layout differs from the PDB");
