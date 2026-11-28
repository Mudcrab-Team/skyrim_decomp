// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using cited declarations and stand-in layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0xfc1330 NiParticleInfo::NiParticleInfo
#include "NiParticleInfo_fc1330.h"

// Initializes particle kinematics and lifetime counters to zero.
NiParticleInfo::NiParticleInfo() :
    velocity(NiPoint3::ZERO),
    age(0.0f),
    lifeSpan(0.0f),
    lastUpdate(0.0f),
    generation(0),
    code(0)
{
}
