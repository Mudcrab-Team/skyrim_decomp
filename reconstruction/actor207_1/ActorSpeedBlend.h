// ActorSpeedBlend: STANDIN GUESS(low); target-bound partial receiver and callee views; original names remain hypotheses.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Origin: original reconstruction; adapted declarations retain their cited source notices.
// Source exposure: mixed; drafted by gpt-6.1-terra.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
namespace P2071 {
// ActorSpeedBlend: STANDIN GUESS(medium); incomplete actor receiver, layout not asserted.
class ActorSpeedBlend { public:
    // LowerSpeed, UpperSpeed: GUESS(low); direct callee names inferred.
    float LowerSpeed();
    float UpperSpeed();
    // GetJogSpeed, GetFastWalkSpeed: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
    float GetJogSpeed();
    float GetFastWalkSpeed();
};
// JogBlend, FastWalkBlend: GUESS(low); named for use, not identified global ownership.
extern float JogBlend;
extern float FastWalkBlend;
}
