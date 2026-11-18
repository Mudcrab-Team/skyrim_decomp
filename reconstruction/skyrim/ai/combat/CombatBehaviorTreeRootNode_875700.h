// Source exposure: mixed
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// CombatBehaviorTreeRootNode::Update: SIBLING(fo4-private@1b765c70, author-permission); adapted using target evidence
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:179
// CombatBehaviorTreeRootNode, CombatBehaviorThread, CombatBehaviorTreeNode, CombatBehaviorStack, buffer, capacity, size, stack, Ascend: GUESS(low); names and declarations are provisional
#pragma once
#include <cstdint>
class CombatBehaviorTreeNode;
struct CombatBehaviorStack {
    unsigned char* buffer;
    std::uint32_t capacity;
    std::uint32_t size;
};
class CombatBehaviorThread {
public:
    CombatBehaviorStack stack;
    void Ascend(const CombatBehaviorTreeNode* node);
};
class CombatBehaviorTreeRootNode {
public:
    void Update(CombatBehaviorThread* thread) const;
};
