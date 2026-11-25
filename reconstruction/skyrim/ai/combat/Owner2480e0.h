// Source exposure: mixed
// Code origin: Stamped as a twin of matched 0x8755c0 (skyrim/ai/combat/CombatBehaviorTreeWrapperNode): source copied, names replaced by placeholders.
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Declarations from powerof3/CommonLibSSE 654e55f7979c1733033d5dbef176e43827bac944, include/RE/C/CombatBehaviorTreeNode.h; GPL-3.0.
// Owner2480e0: GUESS(low) STANDIN
// CombatBehaviorTreeNode, node: GUESS(low) STANDIN
#pragma once
#include "CombatBehaviorTreeWrapperNode.h"

class Owner2480e0: public CombatBehaviorTreeNode { public: const BSFixedString& GetName() override; void Enter(CombatBehaviorThread*) override; void Exit(CombatBehaviorThread*) override; void Update(CombatBehaviorThread*) override; void Abort(CombatBehaviorThread*) override; void SaveGame(CombatBehaviorThread*,BGSSaveFormBuffer*) override; void LoadGame(CombatBehaviorThread*,BGSLoadFormBuffer*) override; bool Validate(const CombatBehaviorTreeNode*) override; CombatBehaviorTreeNode* node; };

