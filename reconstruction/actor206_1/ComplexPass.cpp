// ComplexPass: STANDIN GUESS(low); ordinary receiver identity is provisional.
// Source exposure: mixed (binary-analysis and community-headers).
// Drafted by gpt-6.1-terra. Origin: original reconstruction; community declarations adapted as noted.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x6b15f0 P2061::ComplexPass::UpdateCombatControllerSettings
// 0x6b5200 P2061::ComplexPass::DestroyActorMover
// 0x6cc460 P2061::ComplexPass::Func261
// 0x6c9f60 P2061::ComplexPass::IsCombatTarget
#include "ComplexPass.h"
namespace P2061 {
void ComplexPass::UpdateCombatControllerSettings() { if (reinterpret_cast<const ActorVtable*>(reference.form.vtable)->IsInCombat(this)) UpdateSettings(); }
void ComplexPass::DestroyActorMover() { if (actorMover) { delete actorMover; actorMover = nullptr; } }
void ComplexPass::Func261(Item* item) { if (item) reinterpret_cast<const ActorVtable*>(reference.form.vtable)->AddObject(this,item,nullptr,1,nullptr); }
bool ComplexPass::IsCombatTarget(ComplexPass* actor) { auto* group = reinterpret_cast<const ActorVtable*>(reference.form.vtable)->GetCombatGroup(this); if (group) return group->Contains(actor); return false; }
}
