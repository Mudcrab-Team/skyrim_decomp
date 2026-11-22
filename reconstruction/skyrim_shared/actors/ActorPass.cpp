// Source exposure: mixed (binary-analysis and community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x68be20 P2061::Actor::Function68be20
// 0x6ca140 P2061::Actor::GetEquippedWeapon
// 0x690b20 P2061::Actor::Function690b20
// 0x6a15e0 P2061::Actor::unk_IsInDialogue
#include "ActorPass.h"
namespace P2061 {
// Function68be20, GetEquippedWeapon, Function690b20, unk_IsInDialogue: GUESS(low); receiver and callee identity are provisional.
void* ActorPass::Function68be20() { auto* inventory = reference.extraList.Inventory(); if (inventory) return inventory->UnknownValue(); return nullptr; }
void* ActorPass::GetEquippedWeapon(bool leftHand) { if (currentProcess) { auto* item = currentProcess->EquippedWeapon(leftHand); if (item) return item->form; } return nullptr; }
bool ActorPass::Function690b20() { if (currentProcess) { auto* pkg = currentProcess->RunningPackage(); if (pkg && pkg->kind == 0x17) return true; } return false; }
bool ActorPass::unk_IsInDialogue() { if (currentProcess) { auto* pkg = currentProcess->RunningPackage(); if (pkg && pkg->kind == 0x1c) return true; } return false; }
}
