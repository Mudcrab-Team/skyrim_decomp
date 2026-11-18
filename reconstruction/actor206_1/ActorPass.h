// ActorPass: STANDIN GUESS(low); receiver identity is provisional.
// Source exposure: mixed (binary-analysis and community-headers).
// Drafted by gpt-6.1-terra. Origin: original reconstruction; community declarations adapted as noted.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include "actors/ActorTargetPrefix.h"
namespace P2061 {
// Actor, ExtraDataList, AIProcess: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); receiver is provisional.
// InventoryData, EquippedEntry, PackageData: STANDIN GUESS(low); accessed shapes are provisional.
struct InventoryData { void* UnknownValue(); };
struct ExtraDataList : P206Target::ExtraDataListPrefix { InventoryData* Inventory(); };
struct EquippedEntry { void* form; };
struct PackageData { std::uint8_t unknown00[0x24]; std::uint8_t kind; };
struct AIProcess { EquippedEntry* EquippedWeapon(bool); PackageData* RunningPackage(); };
// Actor: STANDIN GUESS(low); ordinary receiver identity has not been established.
class ActorPass : public P206Target::ActorTargetPrefix<ExtraDataList, AIProcess> {
public:
 // Function68be20, GetEquippedWeapon, Function690b20, unk_IsInDialogue: GUESS(low); names and signatures provisional.
 void* Function68be20(); void* GetEquippedWeapon(bool leftHand); bool Function690b20(); bool unk_IsInDialogue();
};
}
