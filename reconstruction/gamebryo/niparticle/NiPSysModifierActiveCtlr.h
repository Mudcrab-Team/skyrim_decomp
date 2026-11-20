// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using an existing modifier declaration.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysModifier, active, SetActive: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPSysModifierActiveCtlr, GetTargetValue, SetTargetValue, modifier: GUESS(low)
#pragma once

#include <cstdint>

class NiPSysModifier;

class NiPSysModifierActiveCtlr
{
public:
    void GetTargetValue(bool& value) const;
    void SetTargetValue(bool value);

private:
    std::uint8_t padding00[0x58];
    NiPSysModifier* modifier;
};
