// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using cited declarations and stand-in layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0xfc15e0 NiParticleInfo::IsEqual
#include "NiParticleInfo_fc15e0.h"

// Compares all velocity, timing, generation, and code fields of two particle records.
bool NiParticleInfo::IsEqual(const NiParticleInfo& other) const
{
    if (velocity.x != other.velocity.x ||
        velocity.y != other.velocity.y ||
        velocity.z != other.velocity.z ||
        age != other.age ||
        lifeSpan != other.lifeSpan ||
        lastUpdate != other.lastUpdate ||
        generation != other.generation ||
        code != other.code)
    {
        return false;
    }
    return true;
}
