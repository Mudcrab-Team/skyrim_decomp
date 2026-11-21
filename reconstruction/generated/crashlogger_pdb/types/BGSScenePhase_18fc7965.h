// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSScenePhase; size 0x18
// one of 2 different PDB types sharing this name
#pragma once

#include "TESCondition.h"
struct BGSStoryManagerQuestNode;
struct BGSScenePhase_18fc7965 {
    TESCondition startConditions;
    TESCondition completionConditions;
    BGSStoryManagerQuestNode* questNode;
};
static_assert(sizeof(BGSScenePhase_18fc7965) == 24, "BGSScenePhase_18fc7965 layout differs from the PDB");
