// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using an existing modifier declaration.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xfb1300 NiPSysGravityStrengthCtlr::GetTargetValue
// 0xfb1310 NiPSysGravityStrengthCtlr::SetTargetValue
// Adapted bodies: none
#include "NiPSysGravityStrengthCtlr.h"
#include "gamebryo/niparticle/NiPSysGravityModifierLayout.h"

void NiPSysGravityStrengthCtlr::GetTargetValue(float& value) const
{
    value = modifier->strength;
}

void NiPSysGravityStrengthCtlr::SetTargetValue(float value)
{
    modifier->strength = value;
}
