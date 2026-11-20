// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSScene; size 0xc8
// one of 2 different PDB types sharing this name
#pragma once

#include "BSTArray_REX__EnumSet_RE__BGSScene__BehaviourFlag_unsigned_int_87763985.h"
#include "BSTArray_REX__EnumSet_RE__SCENE_ACTOR_FLAG_unsigned_int_fcdf31f9_88a0a4fe.h"
#include "BSTArray_RE__BGSSceneAction_9363a1f7_e7358461.h"
#include "BSTArray_RE__BGSScenePhase_316fb332.h"
#include "BSTArray_unsigned_int_4b643186.h"
#include "Flag_a4a94b8a.h"
#include "TESCondition_4d3cdc88.h"
#include "TESForm.h"
struct TESQuest_fe66f8e1;
struct BGSScene_f16755a1 {
    TESForm _base;
    BSTArray_RE__BGSScenePhase_316fb332 phases;
    BSTArray_unsigned_int_4b643186 actors;
    BSTArray_REX__EnumSet_RE__SCENE_ACTOR_FLAG_unsigned_int_fcdf31f9_88a0a4fe actorFlags;
    BSTArray_REX__EnumSet_RE__BGSScene__BehaviourFlag_unsigned_int_87763985 actorProgressionFlags;
    BSTArray_RE__BGSSceneAction_9363a1f7_e7358461 actions;
    TESQuest_fe66f8e1* parentQuest;
    Flag_a4a94b8a flags;
    unsigned int padA4;
    TESCondition_4d3cdc88 conditions;
    bool isPlaying;
    unsigned char unkB1;
    unsigned char unkB2;
    unsigned char unkB3;
    unsigned int isShuttingDown;
    unsigned int unkB8;
    unsigned int currentPhaseIndex;
    unsigned int unkC0;
    unsigned int padC4;
};
static_assert(sizeof(BGSScene_f16755a1) == 200, "BGSScene_f16755a1 layout differs from the PDB");
