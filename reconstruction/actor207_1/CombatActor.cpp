// CombatActor: STANDIN GUESS(low); target-bound partial receiver and callee views; original names remain hypotheses.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Origin: original reconstruction; adapted declarations retain their cited source notices.
// Source exposure: mixed; drafted by gpt-6.1-terra.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x6c9870 P2071::CombatActor::EngagingInCombat
#include "CombatActor.h"
namespace P2071 {
bool CombatActor::EngagingInCombat() {
    return IsInCombat() && (!currentProcess || !ProcessCheck(currentProcess));
}
}
