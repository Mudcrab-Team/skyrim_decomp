// ScriptActor: STANDIN GUESS(low); target-bound partial receiver and callee views; original names remain hypotheses.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Origin: original reconstruction; adapted declarations retain their cited source notices.
// Source exposure: binary-analysis. Drafted by gpt-6.1-terra.
// 0xa02b20 P2071::ScriptSetRestrained
// 0xa02b60 P2071::ScriptSetDontMove
#include "ScriptActor.h"
namespace P2071 {
void ScriptSetRestrained(void*, unsigned, ScriptActor* actor, bool value) {
    actor->SetRestrained(value);
    if (value) actor->UpdateMovement();
}
void ScriptSetDontMove(void*, unsigned, ScriptActor* actor, bool value) {
    actor->SetDontMove(value);
    if (value) actor->UpdateMovement();
}
}
