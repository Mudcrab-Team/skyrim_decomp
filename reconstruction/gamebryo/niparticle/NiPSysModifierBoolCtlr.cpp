// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementation using the existing blend support declaration.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xfc1a80 NiPSysModifierBoolCtlr::InterpolatorIsCorrectType
// Adapted bodies: none
#include "NiPSysModifierBoolCtlr.h"
#include "gamebryo/nianimation/NiBlendInterpolator.h"

bool NiPSysModifierBoolCtlr::InterpolatorIsCorrectType(const BlendValueSupport* input, std::uint16_t) const
{
    return input->IsBoolValueSupported();
}
