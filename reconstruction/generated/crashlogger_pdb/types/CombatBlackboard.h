// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatBlackboard; size 0x48
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "CombatBehaviorStack.h"
#include "RE__BSTScatterTable_RE__BSCRC32_RE__CombatBlackboardKeyBase_std__equal_to_RE__CombatBla_44187e0e.h"
struct CombatBlackboard {
    RE__BSTScatterTable_RE__BSCRC32_RE__CombatBlackboardKeyBase_std__equal_to_RE__CombatBla_44187e0e stack_offsets;
    CombatBehaviorStack stack;
    unsigned int flags;
    unsigned int pad44;
};
static_assert(sizeof(CombatBlackboard) == 72, "CombatBlackboard layout differs from the PDB");
