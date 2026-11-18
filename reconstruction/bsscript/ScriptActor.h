// ScriptActor: STANDIN GUESS(low); target-bound partial receiver and callee views; original names remain hypotheses.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Origin: original reconstruction; adapted declarations retain their cited source notices.
// Source exposure: binary-analysis. Drafted by gpt-6.1-terra.
#pragma once
namespace P2071 {
// ScriptActor: STANDIN GUESS(low); inferred actor receiver, no layout or ownership asserted.
class ScriptActor {
public:
    // SetRestrained, SetDontMove, UpdateMovement: GUESS(low); direct callee names and signatures inferred.
    void SetRestrained(bool);
    void SetDontMove(bool);
    void UpdateMovement();
};
// ScriptSetRestrained, ScriptSetDontMove: GUESS(low); scripting argument types and names inferred.
void ScriptSetRestrained(void*, unsigned, ScriptActor*, bool);
void ScriptSetDontMove(void*, unsigned, ScriptActor*, bool);
}
