// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSQuestObjective; size 0x28
#pragma once

#include "QUEST_OBJECTIVE_FLAGS.h"
struct TESQuest;
struct TESQuestTarget;
struct BGSQuestObjective {
    unsigned char displayText_raw[8];
    TESQuest* ownerQuest;
    TESQuestTarget** targets;
    unsigned int numTargets;
    unsigned short index;
    bool initialized;
    unsigned char state;  // QUEST_OBJECTIVE_STATE in the PDB is wider than this slot
    QUEST_OBJECTIVE_FLAGS flags;
    unsigned int pad24;
};
static_assert(sizeof(BGSQuestObjective) == 40, "BGSQuestObjective layout differs from the PDB");
