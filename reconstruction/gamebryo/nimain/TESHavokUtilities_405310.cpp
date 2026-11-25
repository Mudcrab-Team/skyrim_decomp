// Source exposure: mixed (community names/prototypes; pinned-image observations).
// Code origin: original; reconstructed from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x405310 TESHavokUtilities::GetDamageForImpact
// Adapted bodies: none
#include "TESHavokUtilities_405310.h"

float TESHavokUtilities::GetDamageForImpact(float mass, float speed)
{
    float damage;
    if (!(mass >= ImpactMinimumMass.value))
        damage = 0.0f;
    else if (!(mass >= ImpactMediumMass.value))
        damage = ImpactLowDamage.value;
    else if (!(mass >= ImpactHighMass.value))
        damage = ImpactMediumDamage.value;
    else
        damage = ImpactHighDamage.value;
    float multiplier = 0.0f;
    if (speed > ImpactMinimumSpeed.value)
        multiplier = ImpactSpeedScale.value * speed + ImpactSpeedOffset.value;
    return multiplier * damage;
}
