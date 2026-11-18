// Shield: STANDIN GUESS(low); receiver and helper identities are provisional.
// Source exposure: mixed (binary-analysis, community-headers).
// Drafted by gpt-6.1-terra. Origin: original reconstruction, community declarations as noted.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include "actors/ActorTargetPrefix.h"
namespace P2061 {
// Shield, supporting interfaces: STANDIN GUESS(low); names and ABI are provisional.
class Shield;
struct EquippedObject { void* object; }; struct ShieldEntry { void* form; }; ShieldEntry* FindShield(void*);
struct ShieldVtable { void* unknown00[127]; EquippedObject* (*Equipped)(Shield*); };
class Shield : public P206Target::ActorTargetPrefix<> { public: void* GetEquippedShield(); };
}
