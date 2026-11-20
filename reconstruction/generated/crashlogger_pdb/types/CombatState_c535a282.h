// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatState; size 0xc0
// one of 2 different PDB types sharing this name
#pragma once

#include "AITimeStamp.h"
#include "AITimer.h"
#include "BSTArray_RE__NiPointer_RE__CombatThreat_30624b65_cd9a9dd6.h"
#include "BSTArray_RE__UnreachableLocation_9f92bd99_8c518823.h"
#include "NiPoint3_a7124070.h"
struct CombatController_f906bf3b;
struct CombatState_c535a282 {
    float unk00;
    bool isFleeing;
    bool isDetected;
    bool targetLost;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
    unsigned char unk0B;
    unsigned int unk0C;
    NiPoint3_a7124070 unk10;
    AITimeStamp activeCombatantLastSeenTime;
    AITimeStamp unk20;
    AITimeStamp lastAttackTimeStamp;
    AITimeStamp unk28;
    AITimer attackDialogueTimer;
    AITimer tauntDialogueTimer;
    AITimer bleedOutDialogueTimer;
    AITimer fleeDialogueTimer;
    unsigned int unk4C;
    BSTArray_RE__NiPointer_RE__CombatThreat_30624b65_cd9a9dd6 combatThreats;
    AITimeStamp unk68;
    unsigned char unk6C;
    unsigned char unk6D;
    unsigned char undefined_6e[2];
    float confidenceModifier;
    float threatValue;
    float unk78;
    unsigned int unk7C;
    BSTArray_RE__UnreachableLocation_9f92bd99_8c518823 unreachableLocations;
    CombatController_f906bf3b* unk98;
    unsigned char unkA0;
    unsigned char undefined_a1[3];
    AITimer strengthUpdateTimer;
    AITimer threatRatioUpdateTimer;
    unsigned char threatUpdateTimer_raw[12];
};
static_assert(sizeof(CombatState_c535a282) == 192, "CombatState_c535a282 layout differs from the PDB");
