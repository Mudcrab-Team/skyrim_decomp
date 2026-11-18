// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: original reconstruction using target listing and anonymous sibling hints.
// GetType: SIBLING(fo4-private@1b765c70, author-permission); src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:331; adapted return behavior.
// BSFixedString and string content: GUESS(low); representation and type name inferred for this attempt.
// 0x8757a0 CombatBehaviorTreeRootNode::GetType
#include "CombatBehaviorTreeRootNode.h"
const BSFixedString& CombatBehaviorTreeRootNode::GetType() const { static BSFixedString type("Root"); return type; }
