// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Declarations from powerof3/CommonLibSSE 654e55f7979c1733033d5dbef176e43827bac944, include/RE/C/CombatBehaviorTreeNode.h; GPL-3.0.
// CombatBehaviorTreeNode: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// CombatBehaviorTreeWrapperNode, CombatBehaviorTreeRootNode, node: GUESS(low); derived layout inferred from target accesses and community base.
#pragma once
class BSFixedString { const char* data; }; class CombatBehaviorThread; class BGSSaveFormBuffer; class BGSLoadFormBuffer;
class CombatBehaviorTreeNode { public: virtual ~CombatBehaviorTreeNode(); virtual const BSFixedString& GetName(); virtual void Enter(CombatBehaviorThread*); virtual void Exit(CombatBehaviorThread*); virtual void Update(CombatBehaviorThread*); virtual void Abort(CombatBehaviorThread*); virtual void SaveGame(CombatBehaviorThread*, BGSSaveFormBuffer*); virtual void LoadGame(CombatBehaviorThread*, BGSLoadFormBuffer*); virtual bool Validate(const CombatBehaviorTreeNode*); virtual const BSFixedString& GetType()=0; BSFixedString name; CombatBehaviorTreeNode* parent; CombatBehaviorTreeNode** children; unsigned int childCount; };
class CombatBehaviorTreeWrapperNode: public CombatBehaviorTreeNode { public: const BSFixedString& GetName() override; void Enter(CombatBehaviorThread*) override; void Exit(CombatBehaviorThread*) override; void Update(CombatBehaviorThread*) override; void Abort(CombatBehaviorThread*) override; void SaveGame(CombatBehaviorThread*,BGSSaveFormBuffer*) override; void LoadGame(CombatBehaviorThread*,BGSLoadFormBuffer*) override; bool Validate(const CombatBehaviorTreeNode*) override; CombatBehaviorTreeNode* node; };
