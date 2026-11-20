// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast.json
// Code origin: original implementations based on the pinned game build.
// 0xf84a40 NiPoint3Interpolator::RegisterStreamables
// 0xf84a90 NiPoint3Interpolator::SaveBinary
// 0xf84ca0 NiPoint3Interpolator::ctor
// 0xf84e30 NiPoint3Interpolator::SetPoseValue
// 0xf84ea0 NiPoint3Interpolator::GetKeyCount
// 0xf84ec0 NiPoint3Interpolator::GetKeyType
// 0xf84ef0 NiPoint3Interpolator::GetKeyArray
// 0xf84f10 NiPoint3Interpolator::GetKeyStride
// 0xf84f30 NiPoint3Interpolator::GetChannelPosed
// 0xf850d0 NiPoint3Interpolator::GuaranteeTimeRange
#include "NiPoint3Interpolator_f84a40.h"
#include "NiStream.h"

// RegisterKeyBasedStreamables, GuaranteeNiPosDataTimeRange: GUESS(low); forwarding callees identified by their call sites.
bool RegisterKeyBasedStreamables(NiKeyBasedInterpolator& interpolator, NiStream& stream);
void GuaranteeNiPosDataTimeRange(NiPosData& data, float start, float end);

// SaveKeyBasedBinary, SavePoseBinary: GUESS(low); serialization callees identified by their call sites.
void SaveKeyBasedBinary(NiKeyBasedInterpolator& interpolator, NiStream& stream);
void SavePoseBinary(const NiPoint3& pose, NiStream& stream);

// invalidPose: GUESS(low); value loaded by the pinned interpolator.
extern const NiPoint3 invalidPose;

bool NiPoint3Interpolator::RegisterStreamables(NiStream& stream)
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

void NiPoint3Interpolator::SaveBinary(NiStream& stream)
{
    SaveKeyBasedBinary(*this, stream);
    SavePoseBinary(pose, stream);
    return stream.SaveLinkID(data);
}

NiPoint3Interpolator::NiPoint3Interpolator(const NiPoint3& value) :
    pose{value.x, value.y, value.z}, data(nullptr), cachedKeyIndex(0)
{
}

void NiPoint3Interpolator::SetPoseValue(const NiPoint3& value)
{
    auto* previous = data;
    if (previous) {
        data = nullptr;
        // Release the key data with an atomic reference decrement before testing for the last reference.
        const auto count = _InterlockedDecrement(reinterpret_cast<volatile long*>(&previous->_refCount));
        if (count == 0) {
            previous->DeleteThis();
        }
    }
    pose.x = value.x;
    pose.y = value.y;
    pose.z = value.z;
}

std::uint32_t NiPoint3Interpolator::GetKeyCount(std::uint16_t) const
{
    if (!data) {
        return 0;
    }
    return data->keyCount;
}

KeyType NiPoint3Interpolator::GetKeyType(std::uint16_t) const
{
    if (!data) {
        return KeyType::kNoInterp;
    }
    return data->keyType;
}

void* NiPoint3Interpolator::GetKeyArray(std::uint16_t) const
{
    if (!data) {
        return nullptr;
    }
    return data->keyArray;
}

std::uint8_t NiPoint3Interpolator::GetKeyStride(std::uint16_t) const
{
    if (!data) {
        return 0;
    }
    return data->keyStride;
}

bool NiPoint3Interpolator::GetChannelPosed(std::uint16_t) const
{
    return !data && (invalidPose.x != pose.x || invalidPose.y != pose.y || invalidPose.z != pose.z);
}

void NiPoint3Interpolator::GuaranteeTimeRange(float start, float end)
{
    if (data) {
        return GuaranteeNiPosDataTimeRange(*data, start, end);
    }
}
