// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSStoryManagerQuestNode; size 0xe0
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BGSStoryManagerNodeBase.h"
#include "BSTArray_RE__TESQuest_d778905a.h"
#include "BSTArray_float_ed3b09d0.h"
#include "BSTScatterTable_RE__BSCRC32_RE__TESQuest_std__equal_to_RE__TESQuest_RE__BSTScatterTable_2018abdc.h"
#include "BSTScatterTable_RE__BSCRC32_RE__TESQuest_std__equal_to_RE__TESQuest_RE__BSTScatterTable_b5a516ec.h"
struct BGSStoryManagerQuestNode {
    BGSStoryManagerNodeBase _base;
    BSTArray_RE__TESQuest_d778905a quests;
    BSTScatterTable_RE__BSCRC32_RE__TESQuest_std__equal_to_RE__TESQuest_RE__BSTScatterTable_b5a516ec perQuestFlags;
    BSTScatterTable_RE__BSCRC32_RE__TESQuest_std__equal_to_RE__TESQuest_RE__BSTScatterTable_2018abdc perQuestHoursUntilReset;
    unsigned int numQuestsToStart;
    unsigned int padC4;
    BSTArray_float_ed3b09d0 childrenLastRun;
};
static_assert(sizeof(BGSStoryManagerQuestNode) == 224, "BGSStoryManagerQuestNode layout differs from the PDB");
