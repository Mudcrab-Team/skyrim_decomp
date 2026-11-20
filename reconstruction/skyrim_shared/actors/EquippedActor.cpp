// EquippedActor: STANDIN GUESS(low); target-bound partial receiver and callee views; original names remain hypotheses.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Origin: original reconstruction; adapted declarations retain their cited source notices.
// Source exposure: mixed; drafted by gpt-6.1-terra.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x6b5ee0 P2071::EquippedActor::CalcEquippedWeight
#include "EquippedActor.h"
namespace P2071 {
float EquippedActor::CalcEquippedWeight() {
    EquipmentSource* source = FindEquipmentSource();
    equippedWeight = source ? source->CalculateWeight(this) : 0.0f;
    return equippedWeight;
}
}
