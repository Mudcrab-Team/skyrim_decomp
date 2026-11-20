// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatBehaviorController; size 0x78
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSTArray_RE__CombatBehaviorThread_9313f61b.h"
#include "BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_a40baccc.h"
struct CombatBehaviorThread;
struct CombatController;
struct CombatBehaviorController {
    CombatBehaviorThread* defaultThread;
    BSTArray_RE__CombatBehaviorThread_9313f61b activeThreads;
    CombatController* combatController;
    BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_a40baccc resources;
    BSTArray_RE__CombatBehaviorThread_9313f61b queued;
    unsigned int nextThreadID;
    unsigned int pad74;
};
static_assert(sizeof(CombatBehaviorController) == 120, "CombatBehaviorController layout differs from the PDB");
