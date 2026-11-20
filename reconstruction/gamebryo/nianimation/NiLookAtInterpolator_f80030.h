// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiLookAtInterpolator: EXE_RTTI
// unknown18, targetName, unknown30, children, SetTargetName, AssignFixedString: GUESS(low)
#pragma once

#include "NiKeyBasedInterpolator_f6e600.h"
#include "NiTimeController_ef7ff0.h"

class NiLookAtInterpolator : public NiInterpolator
{
public:
    bool RegisterStreamables(NiStream& stream) override;
    void GuaranteeTimeRange(float start, float end);
    void SetTargetName(const BSFixedString& name);

private:
    std::uint8_t unknown18[0x10];
    BSFixedString targetName;
    std::uint8_t unknown30[0x20];
    NiTimeRangeInterpolator* children[3];
};
