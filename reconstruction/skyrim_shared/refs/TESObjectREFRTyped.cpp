// Source exposure: mixed.
// Origin: Original reconstruction informed by target access witnesses and community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// TESObjectREFRTyped: STANDIN GUESS(low); receiver identity is provisional.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2f1010 P2062::TESObjectREFRTyped::Function2f1010
// 0x301500 P2062::TESObjectREFRTyped::Function301500
// 0x301540 P2062::TESObjectREFRTyped::Function301540

#include "TESObjectREFRTyped.h"
namespace P2062 {
void TESObjectREFRTyped::Function2f1010(float z) { NiPoint3 p{data.location.x,data.location.y,z}; UpdatePosition(p); }
void TESObjectREFRTyped::Function301500() { if (auto s=FindState()) { SetFlag(s->value,false); Notify(); } }
void TESObjectREFRTyped::Function301540() { if (auto s=FindState()) { SetFlag(s->value,true); Notify(); } }
}
