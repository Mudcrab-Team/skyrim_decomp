// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSScenePhase; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "TESCondition_4d3cdc88.h"
struct BGSStoryManagerQuestNode_b5a3032e;
struct BGSScenePhase {
    TESCondition_4d3cdc88 startConditions;
    TESCondition_4d3cdc88 completionConditions;
    BGSStoryManagerQuestNode_b5a3032e* questNode;
};
static_assert(sizeof(BGSScenePhase) == 24, "BGSScenePhase layout differs from the PDB");
