// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSInstancedQuestObjective; size 0x10
#pragma once

#include "QUEST_OBJECTIVE_STATE.h"
struct BGSQuestObjective;
struct BGSInstancedQuestObjective {
    BGSQuestObjective* Objective;
    unsigned int instanceID;
    QUEST_OBJECTIVE_STATE InstanceState;
};
static_assert(sizeof(BGSInstancedQuestObjective) == 16, "BGSInstancedQuestObjective layout differs from the PDB");
