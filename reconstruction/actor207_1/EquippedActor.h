// EquippedActor: STANDIN GUESS(low); target-bound partial receiver and callee views; original names remain hypotheses.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Origin: original reconstruction; adapted declarations retain their cited source notices.
// Source exposure: mixed; drafted by gpt-6.1-terra.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include "actors/ActorValueTargetPrefix.h"
namespace P2071 {
class EquippedActor;
// EquipmentSource: STANDIN GUESS(low); callee receiver identity unknown.
class EquipmentSource { public:
    // CalculateWeight: GUESS(low); direct callee signature inferred.
    float CalculateWeight(EquippedActor*);
};
// EquippedActor: STANDIN GUESS(medium); partial Actor receiver; no complete layout asserted.
class EquippedActor : public P206Target::ActorValueTargetPrefix<> { public:
    // FindEquipmentSource: GUESS(low); direct callee identity unknown.
    EquipmentSource* FindEquipmentSource();
    // CalcEquippedWeight: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
    float CalcEquippedWeight();
};
}
