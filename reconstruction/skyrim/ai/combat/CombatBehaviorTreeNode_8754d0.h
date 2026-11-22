// Source exposure: mixed (target listing, anonymous sibling and unverified names). Build sse-steam-1-7-104.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:61 (CombatBehaviorTreeNode::Update)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:67 (CombatBehaviorTreeNode::Abort)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:95 (CombatBehaviorTreeNode::FindChildIndex)
// CombatBehaviorTreeNode, Update, Abort: GUESS(low)
// CombatBehaviorTreeNode::FindChild, ::FindChildIndex: SIBLING(fo4-private@1b765c70, author-permission) SYMBOLS(fo4-pdb)
// CombatBehaviorTreeNode::vftable, ::name, ::parent, ::children, ::childCount: GUESS(low); layout from the 40-byte size in the FO4 program database and the listing
// BSFixedString: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSFixedString::data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; the interned string pointer compared by identity
#pragma once

#include <cstdint>

// CombatBehaviorThread, Ascend, thread: GUESS(low)
class CombatBehaviorThread { public: void Ascend(); };

class BSFixedString
{
public:
    const char* data;  // 00
};

class CombatBehaviorTreeNode
{
public:
    void Update(CombatBehaviorThread* thread) const;
    void Abort(CombatBehaviorThread* thread) const;
    CombatBehaviorTreeNode* FindChild(const BSFixedString& id) const;
    std::uint32_t FindChildIndex(const BSFixedString& id) const;

    std::uint64_t vftable;              // 00 (virtual table slot of the real class)
    BSFixedString name;                 // 08
    CombatBehaviorTreeNode* parent;     // 10
    CombatBehaviorTreeNode** children;  // 18
    std::uint32_t childCount;           // 20
    std::uint32_t pad24;                // 24
};
static_assert(sizeof(CombatBehaviorTreeNode) == 0x28, "CombatBehaviorTreeNode size");
