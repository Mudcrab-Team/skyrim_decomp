// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiBoolInterpolator: EXE_RTTI
// NiBoolData: STANDIN EXE_RTTI
// value, data, lastIndex: GUESS(low)
#pragma once

#include "NiKeyBasedInterpolator_f6e600.h"

class NiBoolData : public NiObject
{
};

class NiBoolInterpolator : public NiKeyBasedInterpolator
{
public:
    bool IsEqual(NiObject* object) override;

private:
    std::uint8_t value;
    InterpolatorKeyDataPointer<NiBoolData> data;
    std::uint32_t lastIndex;
};
