// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build.
// 0xf75880 NiBoolInterpolator::RegisterStreamables
// 0xf75a80 NiBoolInterpolator::ctor
// 0xf75ae0 NiBoolInterpolator::ctor
// 0xf75c00 NiBoolInterpolator::SetPoseValue
// 0xf75c60 NiBoolInterpolator::GetKeyCount
// 0xf75c80 NiBoolInterpolator::GetKeyType
// 0xf75cb0 NiBoolInterpolator::GetKeyArray
// 0xf75cd0 NiBoolInterpolator::GetKeyStride
// 0xf75cf0 NiBoolInterpolator::GetChannelPosed
// 0xf75e10 NiBoolInterpolator::GuaranteeTimeRange
#include "NiBoolInterpolator_f75880.h"

// RegisterKeyBasedStreamables, GuaranteeNiBoolDataTimeRange: GUESS(low); forwarding callees identified by their call sites.
bool RegisterKeyBasedStreamables(NiKeyBasedInterpolator& interpolator, NiStream& stream);
void GuaranteeNiBoolDataTimeRange(NiBoolData& data, float start, float end);

// invalidPose: GUESS(low); value loaded by the pinned interpolator.
extern const std::uint8_t invalidPose;

bool NiBoolInterpolator::RegisterStreamables(NiStream& stream)
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

NiBoolInterpolator::NiBoolInterpolator(NiBoolData* keys) :
    pose(invalidPose), data(keys)
{
    if (data) {
        // The interpolator takes ownership through the key data's atomic reference count.
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&data->_refCount));
    }
    cachedKeyIndex = 0;
}

NiBoolInterpolator::NiBoolInterpolator(bool value) :
    pose(value), data(nullptr), cachedKeyIndex(0)
{
}

void NiBoolInterpolator::SetPoseValue(bool value)
{
    auto* previous = data;
    if (previous) {
        data = nullptr;
        // Release the key data with an atomic reference decrement before testing for the last reference.
        if (_InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&previous->_refCount), -1) == 1) {
            previous->DeleteThis();
        }
    }
    pose = value;
}

std::uint32_t NiBoolInterpolator::GetKeyCount(std::uint16_t) const
{
    if (!data) {
        return 0;
    }
    return data->keyCount;
}

KeyType NiBoolInterpolator::GetKeyType(std::uint16_t) const
{
    if (!data) {
        return KeyType::kNoInterp;
    }
    return data->keyType;
}

void* NiBoolInterpolator::GetKeyArray(std::uint16_t) const
{
    if (!data) {
        return nullptr;
    }
    return data->keyArray;
}

std::uint8_t NiBoolInterpolator::GetKeyStride(std::uint16_t) const
{
    if (!data) {
        return 0;
    }
    return data->keyStride;
}

bool NiBoolInterpolator::GetChannelPosed(std::uint16_t) const
{
    return !data && pose != invalidPose;
}

void NiBoolInterpolator::GuaranteeTimeRange(float start, float end)
{
    if (data) {
        return GuaranteeNiBoolDataTimeRange(*data, start, end);
    }
}
