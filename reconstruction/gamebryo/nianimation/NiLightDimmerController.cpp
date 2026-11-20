// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build.
// 0xf7eda0 NiLightDimmerController::RegisterStreamables
// 0xf7edd0 NiLightDimmerController::IsEqual
// 0xf7f090 NiLightDimmerController::GetTargetFade
#include "NiLightDimmerController.h"

// These calls return the base condition in a byte, which the wrappers normalize to bool.
// RegisterFloatController, EqualFloatController: GUESS(low)
std::uint8_t RegisterFloatController(NiFloatInterpController& controller, NiStream& stream);
std::uint8_t EqualFloatController(NiFloatInterpController& controller, NiObject* other);

bool NiLightDimmerController::RegisterStreamables(NiStream& stream)
{
    return RegisterFloatController(*this, stream) != 0;
}

bool NiLightDimmerController::IsEqual(NiObject* other)
{
    return EqualFloatController(*this, other) != 0;
}

void NiLightDimmerController::GetTargetFade(float& out) const
{
    if (target) {
        out = static_cast<const NiLight*>(target)->fade;
    }
}
