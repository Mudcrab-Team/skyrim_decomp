// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSStoryManagerQuestNode; size 0xe0
// one of 2 different PDB types sharing this name
#pragma once

#include "BGSStoryManagerNodeBase_cce81802.h"
#include "BSTArray_RE__TESQuest_d778905a_75e5810a.h"
#include "BSTArray_float_ed3b09d0_c6f3c315.h"
#include "BSTScatterTable_RE__BSCRC32_RE__TESQuest_std__equal_to_RE__TESQuest_RE__BSTScatterTable_2018abdc.h"
#include "BSTScatterTable_RE__BSCRC32_RE__TESQuest_std__equal_to_RE__TESQuest_RE__BSTScatterTable_b5a516ec.h"
struct BGSStoryManagerQuestNode_b5a3032e {
    BGSStoryManagerNodeBase_cce81802 _base;
    BSTArray_RE__TESQuest_d778905a_75e5810a quests;
    BSTScatterTable_RE__BSCRC32_RE__TESQuest_std__equal_to_RE__TESQuest_RE__BSTScatterTable_b5a516ec perQuestFlags;
    BSTScatterTable_RE__BSCRC32_RE__TESQuest_std__equal_to_RE__TESQuest_RE__BSTScatterTable_2018abdc perQuestHoursUntilReset;
    unsigned int numQuestsToStart;
    unsigned int padC4;
    BSTArray_float_ed3b09d0_c6f3c315 childrenLastRun;
};
static_assert(sizeof(BGSStoryManagerQuestNode_b5a3032e) == 224, "BGSStoryManagerQuestNode_b5a3032e layout differs from the PDB");
