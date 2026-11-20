// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatBehaviorTree; size 0x18
#pragma once

#include "BSFixedString_char_83b572b4.h"
struct CombatBehaviorTreeNode;
struct CombatBehaviorTree_vtbl;
struct CombatBehaviorTree {
    CombatBehaviorTree_vtbl* __vftable;
    BSFixedString_char_83b572b4 name;
    CombatBehaviorTreeNode* root;
};
static_assert(sizeof(CombatBehaviorTree) == 24, "CombatBehaviorTree layout differs from the PDB");
