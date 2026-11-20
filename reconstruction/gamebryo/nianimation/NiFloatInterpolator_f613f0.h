// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementation and partial layouts from the pinned accesses and cited declarations.
// NiFloatInterpolator: EXE_RTTI
// RegisterStreamables: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// pose, data, cachedKeyIndex, SetPoseValue: GUESS(low)
#pragma once

#include "NiKeyBasedInterpolator.h"

// NiFloatData: STANDIN EXE_RTTI
class NiFloatData : public NiObject
{
};

class NiFloatInterpolator : public NiKeyBasedInterpolator
{
public:
    bool RegisterStreamables(NiStream& stream) override;
    NiFloatInterpolator(NiFloatData* keys);
    NiFloatInterpolator(float value);
    void SetPoseValue(float value);

private:
    float pose;
    NiFloatData* data;
    std::uint32_t cachedKeyIndex;
};
