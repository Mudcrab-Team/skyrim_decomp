// Shield: STANDIN GUESS(low); receiver and helper identities are provisional.
// Source exposure: mixed (binary-analysis, community-headers).
// Drafted by gpt-6.1-terra. Origin: original reconstruction, community declarations as noted.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x6ca230 P2061::Shield::GetEquippedShield
#include "Shield.h"
namespace P2061 {
void* Shield::GetEquippedShield() { auto* object = reinterpret_cast<const ShieldVtable*>(reference.form.vtable)->Equipped(this)->object; if (object) { auto* shield = FindShield(object); if (shield) return shield->form; } return nullptr; }
}
