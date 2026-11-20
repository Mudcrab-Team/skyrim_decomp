// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:61 (CombatBehaviorTreeNode::Update)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:67 (CombatBehaviorTreeNode::Abort)
// CombatBehaviorTreeNode, Update, Abort: GUESS(low)
// 0x875560 CombatBehaviorTreeNode::Update
// 0x875570 CombatBehaviorTreeNode::Abort
#include "CombatBehaviorTreeNode.h"

void CombatBehaviorTreeNode::Update(CombatBehaviorThread* thread) const { thread->Ascend(); }
void CombatBehaviorTreeNode::Abort(CombatBehaviorThread* thread) const { thread->Ascend(); }
