// Near miss: 55.07% | inline-set
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActorState: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ReadMaxSpeedComponent: GUESS(low); reads an unnamed component of the speed output
// 0x11d6760 ActorState::ReadMaxSpeedComponent
#include "ActorState_11d6760.h"

float ActorState::ReadMaxSpeedComponent()
{
    MaxSpeedData speeds;
    SpeedPair* pair = speeds.pairs;
    std::uint64_t remaining = 5;
    do {
        pair->values[0] = 0.0f;
        pair->values[1] = 0.0f;
        ++pair;
    } while (--remaining);
    speeds.trailing = 0.0f;
    if (DoGetCurrentMaxSpeeds(speeds))
        return speeds.pairs[2].values[0];
    return 0.0f;
}
