// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatController; size 0xd8
// one of 2 different PDB types sharing this name
#pragma once

#include "AITimer.h"
#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
#include "BSTArray_RE__CombatAimController_755075ef.h"
#include "BSTArray_RE__CombatAreaStandard_c8c62cea.h"
#include "BSTArray_RE__CombatTargetSelectorStandard_29e25854_e2b507b2.h"
#include "NiPointer_RE__Actor_71eb6ba3.h"
struct CombatAimController_af40e787;
struct CombatAreaStandard;
struct CombatBehaviorController_e9533d18;
struct CombatBlackboard_fe3d4b7e;
struct CombatGroup_d2c3d29b;
struct CombatInventory_e4d1e3ab;
struct CombatState_c535a282;
struct CombatTargetSelectorStandard;
struct TESCombatStyle;
struct CombatController_f906bf3b {
    CombatGroup_d2c3d29b* combatGroup;
    CombatState_c535a282* state;
    CombatInventory_e4d1e3ab* inventory;
    CombatBlackboard_fe3d4b7e* blackboard;
    CombatBehaviorController_e9533d18* behaviorController;
    BSPointerHandle_RE__Actor_1a35f4b9 attackerHandle;
    BSPointerHandle_RE__Actor_1a35f4b9 targetHandle;
    BSPointerHandle_RE__Actor_1a35f4b9 previousTargetHandle;
    unsigned char stance;  // COMBAT_STANCE in the PDB is wider than this slot
    bool startedCombat;
    unsigned char unk36;
    unsigned char unk37;
    TESCombatStyle* combatStyle;
    bool stoppedCombat;
    bool unk41;
    bool ignoringCombat;
    bool inactive;
    AITimer unk44;
    float lowMovementDelta;
    BSTArray_RE__CombatAimController_755075ef aimControllers;
    CombatAimController_af40e787* currentAimController;
    CombatAimController_af40e787* previousAimController;
    BSTArray_RE__CombatAreaStandard_c8c62cea areas;
    CombatAreaStandard* currentArea;
    BSTArray_RE__CombatTargetSelectorStandard_29e25854_e2b507b2 targetSelectors;
    CombatTargetSelectorStandard* currentTargetSelector;
    CombatTargetSelectorStandard* previousTargetSelector;
    unsigned int handleCount;
    int unkC4;
    NiPointer_RE__Actor_71eb6ba3 cachedAttacker;
    NiPointer_RE__Actor_71eb6ba3 cachedTarget;
};
static_assert(sizeof(CombatController_f906bf3b) == 216, "CombatController_f906bf3b layout differs from the PDB");
