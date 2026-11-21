// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSScene; size 0xc8
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSTArray_REX__EnumSet_RE__BGSScene__BehaviourFlag_unsigned_int_87763985_d93f80f1.h"
#include "BSTArray_REX__EnumSet_RE__SCENE_ACTOR_FLAG_unsigned_int_fcdf31f9.h"
#include "BSTArray_RE__BGSSceneAction_9363a1f7.h"
#include "BSTArray_RE__BGSScenePhase_316fb332_e198f48c.h"
#include "BSTArray_unsigned_int_4b643186_a626a7e9.h"
#include "Flag_d5bcd2af.h"
#include "TESCondition.h"
#include "TESForm_4074aa87.h"
struct TESQuest;
struct BGSScene {
    TESForm_4074aa87 _base;
    BSTArray_RE__BGSScenePhase_316fb332_e198f48c phases;
    BSTArray_unsigned_int_4b643186_a626a7e9 actors;
    BSTArray_REX__EnumSet_RE__SCENE_ACTOR_FLAG_unsigned_int_fcdf31f9 actorFlags;
    BSTArray_REX__EnumSet_RE__BGSScene__BehaviourFlag_unsigned_int_87763985_d93f80f1 actorProgressionFlags;
    BSTArray_RE__BGSSceneAction_9363a1f7 actions;
    TESQuest* parentQuest;
    Flag_d5bcd2af flags;
    unsigned int padA4;
    TESCondition conditions;
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
static_assert(sizeof(BGSScene) == 200, "BGSScene layout differs from the PDB");
