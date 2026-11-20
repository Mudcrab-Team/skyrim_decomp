// ActorSpeedBlend: STANDIN GUESS(low); target-bound partial receiver and callee views; original names remain hypotheses.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Origin: original reconstruction; adapted declarations retain their cited source notices.
// Source exposure: mixed; drafted by gpt-6.1-terra.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x692670 P2071::ActorSpeedBlend::GetJogSpeed
// 0x6926b0 P2071::ActorSpeedBlend::GetFastWalkSpeed
#include "ActorSpeedBlend.h"
namespace P2071 {
float ActorSpeedBlend::GetJogSpeed() {
    float low = LowerSpeed();
    return low + (UpperSpeed() - low) * JogBlend;
}
float ActorSpeedBlend::GetFastWalkSpeed() {
    float low = LowerSpeed();
    return low + (UpperSpeed() - low) * FastWalkBlend;
}
}
