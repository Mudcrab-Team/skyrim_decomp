// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x6c47a0 Actor::ReduceVoiceRecovery6c47a0
// Adapted bodies: none
#include "Actor_6c47a0.h"

#include <cmath>

void Actor::ReduceVoiceRecovery6c47a0(float amount)
{
    float time = GetVoiceRecoveryTime();
    if (std::fabs(time) > 0.0001f) {
        time = time - amount;
        if (time < 0.0f) {
            time = 0.0f;
        }
    }
    SetVoiceRecovery6d92d0(time);
}
