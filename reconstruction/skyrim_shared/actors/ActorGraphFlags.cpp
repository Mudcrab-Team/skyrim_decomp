// Source exposure: mixed.
// Origin: Original reconstruction informed by target access witnesses and community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// ActorGraphFlags, GraphHolder, KeyTable, GraphKey, GetKeyTable, SetBool, Function673cc0, Function6aec10: STANDIN GUESS(low); inferred from receiver offsets and target calls.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x673cc0 P2062::ActorGraphFlags::Function673cc0
// 0x6aec10 P2062::ActorGraphFlags::Function6aec10

#include "ActorGraphFlags.h"
namespace P2062 {
void ActorGraphFlags::Function673cc0(bool value) { auto keys=GetKeyTable(); reinterpret_cast<GraphHolder*>(&reference.animationGraphHolder)->SetBool(keys->injured,value); }
void ActorGraphFlags::Function6aec10(bool value) { auto keys=GetKeyTable(); reinterpret_cast<GraphHolder*>(&reference.animationGraphHolder)->SetBool(keys->sprint,value); }
}
