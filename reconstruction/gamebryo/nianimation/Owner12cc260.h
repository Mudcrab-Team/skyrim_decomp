// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code. Stamped as a twin of matched 0xf81060 (gamebryo/nianimation/NiLookAtInterpolator_f80030): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// AssignFixedString_12cc260, Function12cc260, Owner12cc260: GUESS(low) STANDIN
// unknown18, targetName, unknown30, children: GUESS(low) STANDIN
#pragma once
#include "NiLookAtInterpolator_f80030.h"

class Owner12cc260 : public NiInterpolator
{
public:
    bool RegisterStreamables(NiStream& stream) override;
    void GuaranteeTimeRange(float start, float end);
    void Function12cc260(const BSFixedString& name);

private:
    std::uint8_t unknown18[0x10];
    BSFixedString targetName;
    std::uint8_t unknown30[0x20];
    NiTimeRangeInterpolator* children[3];
};

