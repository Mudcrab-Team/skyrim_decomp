// Source exposure: mixed
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// CombatBehaviorTreeRootNode::Update: SIBLING(fo4-private@1b765c70, author-permission); adapted using target evidence
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:179
// CombatBehaviorTreeRootNode, CombatBehaviorThread, CombatBehaviorTreeNode, CombatBehaviorStack, buffer, capacity, size, stack, Ascend: GUESS(low); names and declarations are provisional
// 0x875700 CombatBehaviorTreeRootNode::Update
#include "CombatBehaviorTreeRootNode.h"
void CombatBehaviorTreeRootNode::Update(CombatBehaviorThread* thread) const {
    unsigned int position = thread->stack.size - 8;
    const CombatBehaviorTreeNode* node = *reinterpret_cast<const CombatBehaviorTreeNode**>(thread->stack.buffer + position);
    thread->stack.size -= 8;
    thread->Ascend(node);
}
