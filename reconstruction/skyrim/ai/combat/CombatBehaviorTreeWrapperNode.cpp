// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// CombatBehaviorTreeWrapperNode::GetName: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:271
// CombatBehaviorTreeWrapperNode::Enter: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:277
// CombatBehaviorTreeWrapperNode::Exit: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:283
// CombatBehaviorTreeWrapperNode::Update: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:289
// CombatBehaviorTreeWrapperNode::Abort: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:295
// CombatBehaviorTreeWrapperNode::SaveGame: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:301
// CombatBehaviorTreeWrapperNode::LoadGame: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:307
// CombatBehaviorTreeWrapperNode::Validate: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:319
// 0x8755c0 CombatBehaviorTreeWrapperNode::GetName
// 0x8755e0 CombatBehaviorTreeWrapperNode::Enter
// 0x875600 CombatBehaviorTreeWrapperNode::Exit
// 0x875620 CombatBehaviorTreeWrapperNode::Update
// 0x875640 CombatBehaviorTreeWrapperNode::Abort
// 0x875660 CombatBehaviorTreeWrapperNode::SaveGame
// 0x875680 CombatBehaviorTreeWrapperNode::LoadGame
// 0x8756a0 CombatBehaviorTreeWrapperNode::Validate
#include "CombatBehaviorTreeWrapperNode.h"
const BSFixedString& CombatBehaviorTreeWrapperNode::GetName() { return node->GetName(); }
void CombatBehaviorTreeWrapperNode::Enter(CombatBehaviorThread* t) { node->Enter(t); }
void CombatBehaviorTreeWrapperNode::Exit(CombatBehaviorThread* t) { node->Exit(t); }
void CombatBehaviorTreeWrapperNode::Update(CombatBehaviorThread* t) { node->Update(t); }
void CombatBehaviorTreeWrapperNode::Abort(CombatBehaviorThread* t) { node->Abort(t); }
void CombatBehaviorTreeWrapperNode::SaveGame(CombatBehaviorThread* t, BGSSaveFormBuffer* b) { node->SaveGame(t,b); }
void CombatBehaviorTreeWrapperNode::LoadGame(CombatBehaviorThread* t, BGSLoadFormBuffer* b) { node->LoadGame(t,b); }
bool CombatBehaviorTreeWrapperNode::Validate(const CombatBehaviorTreeNode* n) { return node->Validate(n); }
