// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementation using the existing blend support declaration.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xfc0d60 NiPSysModifierFloatCtlr::InterpolatorIsCorrectType
// Adapted bodies: none
#include "NiPSysModifierFloatCtlr.h"
#include "gamebryo/nianimation/NiBlendInterpolator.h"

bool NiPSysModifierFloatCtlr::InterpolatorIsCorrectType(const BlendValueSupport* input, std::uint16_t) const
{
    return input->IsFloatValueSupported();
}
