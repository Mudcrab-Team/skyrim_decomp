// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// CombatBehaviorTreeRootNode::Abort: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:325
// 0x875730 CombatBehaviorTreeRootNode::Abort
#include "CombatBehaviorTreeRootNode.h"
void CombatBehaviorTreeRootNode::Abort(CombatBehaviorThread* t) { Update(t); }
