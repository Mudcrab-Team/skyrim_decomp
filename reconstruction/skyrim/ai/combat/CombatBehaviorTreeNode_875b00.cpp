// Source exposure: mixed (sibling source; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x875b00 CombatBehaviorTreeNode::~CombatBehaviorTreeNode
// Adapted bodies: CombatBehaviorTreeNode::~CombatBehaviorTreeNode from the sibling source named in the header
#include "CombatBehaviorTreeNode_875b00.h"

CombatBehaviorTreeNode::CombatBehaviorTreeNode()
    : Name(), pChildArray(nullptr), uiChildCount(0)
{
}

CombatBehaviorTreeNode::~CombatBehaviorTreeNode()
{
    for (std::uint32_t i = 0; i < uiChildCount; ++i) {
        CombatBehaviorTreeNode* child = pChildArray[i];
        if (child) {
            delete child;
        }
    }
}
