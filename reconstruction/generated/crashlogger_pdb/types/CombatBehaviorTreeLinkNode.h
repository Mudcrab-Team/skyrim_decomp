// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatBehaviorTreeLinkNode; size 0x30
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "CombatBehaviorTreeNode.h"
struct CombatBehaviorTreeLinkNode {
    CombatBehaviorTreeNode _base;
    BSFixedString_char_83b572b4 linkName;
};
static_assert(sizeof(CombatBehaviorTreeLinkNode) == 48, "CombatBehaviorTreeLinkNode layout differs from the PDB");
