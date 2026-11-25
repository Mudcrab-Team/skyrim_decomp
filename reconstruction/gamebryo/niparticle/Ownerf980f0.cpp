// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementation using the existing blend support declaration. Stamped as a twin of matched 0xfc0d60 (gamebryo/niparticle/NiPSysModifierFloatCtlr): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xf980f0 Ownerf980f0::Functionf980f0
#include "Ownerf980f0.h"
#include "gamebryo/nianimation/NiBlendInterpolator.h"

// guess: same compiled code as matched 0xfc0d60 apart from relocated fields; its role here is not established.
bool Ownerf980f0::Functionf980f0(const BlendValueSupport* input, std::uint16_t) const
{
    return input->IsFloatValueSupported();
}
