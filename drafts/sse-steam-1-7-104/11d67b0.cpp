// Near miss: 78.26% | inline-set
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActorState, Movement, MaxSpeeds, speeds, rotateWhileMovingRun: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// DoGetCurrentMaxSpeeds: SYMBOLS(tesv-2013-map)
// GetForwardRunSpeed: GUESS(low); queried forward running component
// 0x11d67b0 ActorState::GetForwardRunSpeed
#include "ActorState_11d67b0.h"

// Return the queried forward running speed, or zero when unavailable.
float ActorState::GetForwardRunSpeed()
{
    Movement::MaxSpeeds maximum;
    for (auto& direction : maximum.speeds)
    {
        direction[0] = 0.0f;
        direction[1] = 0.0f;
    }
    maximum.rotateWhileMovingRun = 0.0f;
    if (DoGetCurrentMaxSpeeds(maximum))
    {
        return maximum.speeds[2][1];
    }
    return 0.0f;
}
