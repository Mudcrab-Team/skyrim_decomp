// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build.
// 0xf85580 NiQuaternionInterpolator::RegisterStreamables
// 0xf855d0 NiQuaternionInterpolator::SaveBinary
// 0xf85960 NiQuaternionInterpolator::SetPoseValue
// 0xf859c0 NiQuaternionInterpolator::GetKeyCount
// 0xf859e0 NiQuaternionInterpolator::GetKeyType
// 0xf85a10 NiQuaternionInterpolator::GetKeyArray
// 0xf85a30 NiQuaternionInterpolator::GetKeyStride
// 0xf85cc0 NiQuaternionInterpolator::GuaranteeTimeRange
#include "NiQuaternionInterpolator_f85580.h"
#include "NiStream.h"

// RegisterKeyBasedStreamables, GuaranteeNiRotDataTimeRange: GUESS(low); forwarding callees identified by their call sites.
bool RegisterKeyBasedStreamables(NiKeyBasedInterpolator& interpolator, NiStream& stream);
void GuaranteeNiRotDataTimeRange(NiRotData& data, float start, float end);

// SaveKeyBasedBinary, SavePoseBinary: GUESS(low); serialization callees identified by their call sites.
void SaveKeyBasedBinary(NiKeyBasedInterpolator& interpolator, NiStream& stream);
void SavePoseBinary(const NiQuaternion& pose, NiStream& stream);

bool NiQuaternionInterpolator::RegisterStreamables(NiStream& stream)
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

void NiQuaternionInterpolator::SaveBinary(NiStream& stream)
{
    SaveKeyBasedBinary(*this, stream);
    SavePoseBinary(pose, stream);
    return stream.SaveLinkID(data);
}

void NiQuaternionInterpolator::SetPoseValue(const NiQuaternion& value)
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
    pose = value;
}

std::uint32_t NiQuaternionInterpolator::GetKeyCount(std::uint16_t) const
{
    if (!data) {
        return 0;
    }
    return data->keyCount;
}

KeyType NiQuaternionInterpolator::GetKeyType(std::uint16_t) const
{
    if (!data) {
        return KeyType::kNoInterp;
    }
    return data->keyType;
}

void* NiQuaternionInterpolator::GetKeyArray(std::uint16_t) const
{
    if (!data) {
        return nullptr;
    }
    return data->keyArray;
}

std::uint8_t NiQuaternionInterpolator::GetKeyStride(std::uint16_t) const
{
    if (!data) {
        return 0;
    }
    return data->keyStride;
}

void NiQuaternionInterpolator::GuaranteeTimeRange(float start, float end)
{
    if (data) {
        return GuaranteeNiRotDataTimeRange(*data, start, end);
    }
}
