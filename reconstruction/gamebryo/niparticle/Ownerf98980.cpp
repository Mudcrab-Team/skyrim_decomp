// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementation using the existing blend support declaration. Stamped as a twin of matched 0xfc1a80 (gamebryo/niparticle/NiPSysModifierBoolCtlr): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xf98980 Ownerf98980::Functionf98980
#include "Ownerf98980.h"
#include "gamebryo/nianimation/NiBlendInterpolator.h"

// guess: same compiled code as matched 0xfc1a80 apart from relocated fields; its role here is not established.
bool Ownerf98980::Functionf98980(const BlendValueSupport* input, std::uint16_t) const
{
    return input->IsBoolValueSupported();
}
