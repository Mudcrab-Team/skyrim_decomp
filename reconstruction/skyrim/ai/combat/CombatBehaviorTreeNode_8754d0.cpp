// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:61 (CombatBehaviorTreeNode::Update)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:67 (CombatBehaviorTreeNode::Abort)
// CombatBehaviorTreeNode, Update, Abort: GUESS(low)
// Code origin: FindChild adapted from the sibling source below; Update and Abort as declared in the header.
// SPDX-License-Identifier: CC0-1.0
// 0x8754d0 CombatBehaviorTreeNode::FindChild
// Adapted bodies: FindChild from fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:86 (author-permission).
#include "CombatBehaviorTreeNode_8754d0.h"

std::uint32_t CombatBehaviorTreeNode::FindChildIndex(const BSFixedString& id) const
{
    for (std::uint32_t i = 0; i < childCount; ++i) {
        if (children[i]->name.data == id.data) {
            return i;
        }
    }
    return 0xFFFFFFFFu;
}

CombatBehaviorTreeNode* CombatBehaviorTreeNode::FindChild(const BSFixedString& id) const
{
    const std::uint32_t index = FindChildIndex(id);
    if (index == 0xFFFFFFFFu) {
        return nullptr;
    }
    return children[index];
}
