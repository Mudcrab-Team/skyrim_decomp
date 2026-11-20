// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build.
// 0xf634d0 NiTransformInterpolator::RegisterStreamables
// 0xf63520 NiTransformInterpolator::SaveBinary
// 0xf63a90 NiTransformInterpolator::GetKeyCount
// 0xf63ae0 NiTransformInterpolator::GetKeyType
// 0xf63b30 NiTransformInterpolator::GetKeyContent
// 0xf63b60 NiTransformInterpolator::GetKeyArray
// 0xf63bb0 NiTransformInterpolator::GetKeyStride
// 0xf64240 NiTransformInterpolator::GuaranteeTimeRange
#include "NiTransformInterpolator_f634d0.h"

#include "NiStream.h"

// The forwarding callees are declared from their measured use sites.
// RegisterKeyBasedStreamables, SaveKeyBasedBinary, SaveTransformValue, GuaranteeTransformDataTimeRange: GUESS(low)
bool RegisterKeyBasedStreamables(NiKeyBasedInterpolator& interpolator, NiStream& stream);
void SaveKeyBasedBinary(NiKeyBasedInterpolator& interpolator, NiStream& stream);
void SaveTransformValue(const NiQuatTransform& value, NiStream& stream);
void GuaranteeTransformDataTimeRange(NiTransformData& data, float start, float end);

bool NiTransformInterpolator::RegisterStreamables(NiStream& stream)
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

void NiTransformInterpolator::SaveBinary(NiStream& stream)
{
    SaveKeyBasedBinary(*this, stream);
    SaveTransformValue(value, stream);
    return stream.SaveLinkID(data);
}

std::uint32_t NiTransformInterpolator::GetKeyCount(std::uint16_t channel) const
{
    if (channel == 0) {
        if (data) {
            return data->translationCount;
        }
    } else if (channel == 1) {
        if (data) {
            return data->rotationCount;
        }
    } else if (channel == 2 && data) {
        return data->scaleCount;
    }
    return 0;
}

KeyType NiTransformInterpolator::GetKeyType(std::uint16_t channel) const
{
    if (channel == 0) {
        if (data) {
            return data->translationType;
        }
    } else if (channel == 1) {
        if (data) {
            return data->rotationType;
        }
    } else if (channel == 2 && data) {
        return data->scaleType;
    }
    return KeyType::kNoInterp;
}

KeyContent NiTransformInterpolator::GetKeyContent(std::uint16_t channel) const
{
    if (channel == 0) {
        return KeyContent::kPos;
    }
    if (channel == 1) {
        return KeyContent::kRot;
    }
    return channel == 2 ? KeyContent::kFloat : KeyContent::kTotal;
}

void* NiTransformInterpolator::GetKeyArray(std::uint16_t channel) const
{
    if (channel == 0) {
        if (data) {
            return data->translationKeys;
        }
    } else if (channel == 1) {
        if (data) {
            return data->rotationKeys;
        }
    } else if (channel == 2 && data) {
        return data->scaleKeys;
    }
    return nullptr;
}

std::uint8_t NiTransformInterpolator::GetKeyStride(std::uint16_t channel) const
{
    if (channel == 0) {
        if (data) {
            return data->translationStride;
        }
    } else if (channel == 1) {
        if (data) {
            return data->rotationStride;
        }
    } else if (channel == 2 && data) {
        return data->scaleStride;
    }
    return 0;
}

void NiTransformInterpolator::GuaranteeTimeRange(float start, float end)
{
    if (data) {
        return GuaranteeTransformDataTimeRange(*data, start, end);
    }
}
