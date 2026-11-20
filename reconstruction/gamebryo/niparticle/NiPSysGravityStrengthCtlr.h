// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using an existing modifier declaration.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysGravityModifier, strength: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPSysGravityStrengthCtlr, GetTargetValue, SetTargetValue, modifier: GUESS(low)
#pragma once

#include <cstdint>

namespace ResearchLayouts { class NiPSysGravityModifierLayout; }

class NiPSysGravityStrengthCtlr
{
public:
    void GetTargetValue(float& value) const;
    void SetTargetValue(float value);

private:
    std::uint8_t padding00[0x58];
    ResearchLayouts::NiPSysGravityModifierLayout* modifier;
};
