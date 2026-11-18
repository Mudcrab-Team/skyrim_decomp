// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: original reconstruction using target listing and anonymous sibling hints.
// GetType: SIBLING(fo4-private@1b765c70, author-permission); src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:331; adapted return behavior.
// BSFixedString and string content: GUESS(low); representation and type name inferred for this attempt.
#pragma once
struct BSFixedString { const char* data; BSFixedString(const char*); ~BSFixedString(); };
class CombatBehaviorTreeRootNode { public: const BSFixedString& GetType() const; };
