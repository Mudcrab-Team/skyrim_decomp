// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiFloatInterpolator: EXE_RTTI
// NiFloatData: STANDIN EXE_RTTI
// CopyMembers: GUESS(low)
// NiFloatInterpolator::floatValue, ::floatData, ::lastIndex: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include "NiKeyBasedInterpolator_f6e600.h"

class NiFloatData : public NiObject
{
};

class NiFloatInterpolator : public NiKeyBasedInterpolator
{
public:
    void CopyMembers(NiFloatInterpolator* dest) const;

private:
    float floatValue;
    InterpolatorKeyDataPointer<NiFloatData> floatData;
    std::uint32_t lastIndex;
};
