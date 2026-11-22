// Blocking: STANDIN GUESS(low); receiver and helper identities are provisional.
// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x6aef60 P2061::Blocking::IsBlocking
#include "Blocking.h"
namespace P2061 {
bool Blocking::IsBlocking() { bool value = false; auto* names = GetGraphNames(); reinterpret_cast<const GraphVtable*>(reference.animationGraphHolder.vtable)->GetBoolean(&reference.animationGraphHolder, &names->blocking, &value); return value; }
}
