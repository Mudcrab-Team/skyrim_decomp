// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// CombatBehaviorTreeRootNode::Validate: SIBLING(fo4-private@1b765c70, author-permission); adapted to the target's simplified predicate.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:190
// names: GUESS(low); names are unverified.
// 0x875740 CombatBehaviorTreeRootNode::Validate
#include "CombatBehaviorTreeRootNode_875740.h"
bool CombatBehaviorTreeRootNode::Validate(const CombatBehaviorTreeNode* node) { return node->childCount == 1 && !node->parent; }
