// ChangeActor: STANDIN GUESS(low); partial target-bound receiver/callee view, no complete layout or ownership asserted.
// Origin: original reconstruction; cited adapted declarations retain complete notices.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Source exposure: mixed; drafted by gpt-6.1-terra.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x6c8060 P2071::ChangeActor::ResetActorChange
#include "ChangeActor.h"
namespace P2071 {
void ChangeActor::ResetActorChange() {
    ClearExtra(&extraList);
    AddChange(0x80000000u);
    if (combatController) ResetCombatController(combatController);
}
}
