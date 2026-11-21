// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatController; size 0xe0
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "AITimer.h"
#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
#include "BSSpinLock.h"
#include "BSTArray_RE__CombatAimController_755075ef_cb8f1aac.h"
#include "BSTArray_RE__CombatAreaStandard_c8c62cea_ed4fca0a.h"
#include "BSTArray_RE__CombatTargetSelectorStandard_29e25854.h"
#include "NiPointer_RE__Actor_71eb6ba3.h"
struct CombatAimController;
struct CombatAreaStandard_84057697;
struct CombatBehaviorController;
struct CombatBlackboard;
struct CombatGroup;
struct CombatInventory;
struct CombatState;
struct CombatTargetSelectorStandard_9cf94820;
struct TESCombatStyle_cff5b770;
struct CombatController {
    CombatGroup* combatGroup;
    CombatState* state;
    CombatInventory* inventory;
    CombatBlackboard* blackboard;
    CombatBehaviorController* behaviorController;
    BSPointerHandle_RE__Actor_1a35f4b9 attackerHandle;
    BSPointerHandle_RE__Actor_1a35f4b9 targetHandle;
    BSPointerHandle_RE__Actor_1a35f4b9 previousTargetHandle;
    unsigned char stance;  // COMBAT_STANCE in the PDB is wider than this slot
    bool startedCombat;
    unsigned char unk36;
    unsigned char unk37;
    TESCombatStyle_cff5b770* combatStyle;
    bool stoppedCombat;
    bool unk41;
    bool ignoringCombat;
    bool inactive;
    AITimer unk44;
    float lowMovementDelta;
    BSTArray_RE__CombatAimController_755075ef_cb8f1aac aimControllers;
    BSSpinLock aimControllerLock;
    CombatAimController* currentAimController;
    CombatAimController* previousAimController;
    BSTArray_RE__CombatAreaStandard_c8c62cea_ed4fca0a areas;
    CombatAreaStandard_84057697* currentArea;
    BSTArray_RE__CombatTargetSelectorStandard_29e25854 targetSelectors;
    CombatTargetSelectorStandard_9cf94820* currentTargetSelector;
    CombatTargetSelectorStandard_9cf94820* previousTargetSelector;
    unsigned int handleCount;
    int unkC4;
    NiPointer_RE__Actor_71eb6ba3 cachedAttacker;
    NiPointer_RE__Actor_71eb6ba3 cachedTarget;
};
static_assert(sizeof(CombatController) == 224, "CombatController layout differs from the PDB");
