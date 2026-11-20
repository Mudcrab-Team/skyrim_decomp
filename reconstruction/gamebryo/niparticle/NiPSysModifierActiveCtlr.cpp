// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using an existing modifier declaration.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xfb57b0 NiPSysModifierActiveCtlr::GetTargetValue
// 0xfb57d0 NiPSysModifierActiveCtlr::SetTargetValue
// Adapted bodies: none
#include "NiPSysModifierActiveCtlr.h"
#include "gamebryo/niparticle/NiPSysModifier.h"

void NiPSysModifierActiveCtlr::GetTargetValue(bool& value) const
{
    value = modifier->active;
}

void NiPSysModifierActiveCtlr::SetTargetValue(bool value)
{
    if (modifier->active != value) {
        modifier->SetActive(value);
    }
}
