// Source exposure: mixed
// Origin: authorized sibling and public declarations
// GPL-3.0: declarations adapted from powerof3/CommonLibSSE at 654e55f7979c1733033d5dbef176e43827bac944, include/RE/C/CombatBehaviorThread.h, CombatBehaviorStack.h, CombatBehaviorTreeNode.h and include/RE/B/BSTArray.h.
// CombatBehaviorThread, CombatBehaviorStack, CombatBehaviorTreeNode: COMMUNITY(powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944, GPL-3.0); declarations adapted
// names: GUESS(low); method signatures and auxiliary names remain provisional
// CombatBehaviorTreeRootNode::Enter: SIBLING(fo4-private@1b765c70, author-permission); adapted using target evidence
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:165
// 0x8756c0 CombatBehaviorTreeRootNode::Enter
#include "CombatBehaviorTreeRootNode_8756c0.h"
void CombatBehaviorTreeRootNode::Enter(CombatBehaviorThread* thread) {
    {
        const CombatBehaviorTreeNode* previous = thread->previousNode;
        thread->Push(&previous);
    }
    thread->Descend(0);
}
