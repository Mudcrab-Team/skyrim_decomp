// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build.
// 0xf613f0 NiFloatInterpolator::RegisterStreamables
// 0xf615f0 NiFloatInterpolator::ctor
// 0xf61650 NiFloatInterpolator::ctor
// 0xf61770 NiFloatInterpolator::SetPoseValue
#include "NiFloatInterpolator_f613f0.h"

// invalidPose, RegisterKeyBasedStreamables: GUESS(low); default pose and inherited registration call.
extern const float invalidPose;
bool RegisterKeyBasedStreamables(NiKeyBasedInterpolator& interpolator, NiStream& stream);

bool NiFloatInterpolator::RegisterStreamables(NiStream& stream)
{
    const bool registered = RegisterKeyBasedStreamables(*this, stream);
    if (!registered) {
        return registered;
    }
    if (data) {
        data->RegisterStreamables(stream);
    }
    return true;
}

NiFloatInterpolator::NiFloatInterpolator(NiFloatData* keys)
{
    pose = invalidPose;
    data = keys;
    if (data) {
        // Retain the key track through its atomic reference count.
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&data->_refCount));
    }
    cachedKeyIndex = 0;
}

NiFloatInterpolator::NiFloatInterpolator(float value)
{
    pose = value;
    data = nullptr;
    cachedKeyIndex = 0;
}

void NiFloatInterpolator::SetPoseValue(float value)
{
    auto* previous = data;
    if (previous) {
        data = nullptr;
        // Release the key track through its atomic reference count.
        if (_InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&previous->_refCount), -1) == 1) {
            previous->DeleteThis();
        }
    }
    pose = value;
}
