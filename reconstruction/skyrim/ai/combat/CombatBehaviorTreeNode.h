// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:61 (CombatBehaviorTreeNode::Update)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:67 (CombatBehaviorTreeNode::Abort)
// CombatBehaviorTreeNode, Update, Abort: GUESS(low)
#pragma once

// CombatBehaviorThread, Ascend, thread: GUESS(low)
class CombatBehaviorThread { public: void Ascend(); };
class CombatBehaviorTreeNode { public: void Update(CombatBehaviorThread* thread) const; void Abort(CombatBehaviorThread* thread) const; };
