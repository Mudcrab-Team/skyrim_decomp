// PlayerCombatView: STANDIN GUESS(low); target-bound partial receiver and callee views; original names remain hypotheses.
// Origin: original reconstruction; adapted declarations retain their cited source notices.
// Source exposure: mixed; drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// CombatGroup, combatGroup: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); target type is inferred.
// PlayerCombatView, ClearCombat, Remove, member windows: STANDIN GUESS(medium); partial receiver and callee contract, ownership unknown.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x776a40 ClearCombat
#include "PlayerCombatView.h"
namespace P2072 {
void PlayerCombatView::ClearCombat() {
    auto& members = PlayerCharacterMembers::Get<CombatWindow, CombatBinding>(this);
    if (members.combatGroup) {
        members.combatGroup->Remove(this);
        members.combatGroup = nullptr;
    }
}
}
