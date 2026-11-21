// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatBehaviorTreeNode; size 0x28
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "BSStaticArray_RE__CombatBehaviorTreeNode_9cc2f166.h"
struct CombatBehaviorTreeNode_vtbl;
struct CombatBehaviorTreeNode {
    CombatBehaviorTreeNode_vtbl* __vftable;
    BSFixedString_char_83b572b4 name;
    CombatBehaviorTreeNode* parent;
    BSStaticArray_RE__CombatBehaviorTreeNode_9cc2f166 children;
};
static_assert(sizeof(CombatBehaviorTreeNode) == 40, "CombatBehaviorTreeNode layout differs from the PDB");
