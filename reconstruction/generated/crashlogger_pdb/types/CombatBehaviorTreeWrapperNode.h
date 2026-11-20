// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatBehaviorTreeWrapperNode; size 0x30
#pragma once

#include "CombatBehaviorTreeNode.h"
struct CombatBehaviorTreeWrapperNode {
    CombatBehaviorTreeNode _base;
    CombatBehaviorTreeNode* wrapped;
};
static_assert(sizeof(CombatBehaviorTreeWrapperNode) == 48, "CombatBehaviorTreeWrapperNode layout differs from the PDB");
