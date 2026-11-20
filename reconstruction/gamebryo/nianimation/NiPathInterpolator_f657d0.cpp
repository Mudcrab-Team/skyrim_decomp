// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build.
// 0xf657d0 NiPathInterpolator::GetKeyCount
// 0xf65800 NiPathInterpolator::GetKeyType
// 0xf65830 NiPathInterpolator::GetKeyContent
// 0xf65850 NiPathInterpolator::GetKeyArray
// 0xf65880 NiPathInterpolator::GetKeyStride
// 0xf659a0 NiPathInterpolator::GuaranteeTimeRange
// 0xf65a90 NiPathInterpolator::ProcessClone
#include "NiPathInterpolator_f657d0.h"

// GuaranteeFloatTimeRange: GUESS(low); name follows the existing NiFloatInterpolator unit.
void GuaranteeFloatTimeRange(void* data, float start, float end);

std::uint32_t NiPathInterpolator::GetKeyCount(std::uint16_t channel) const
{
    if (channel == 0) {
        if (positionData) {
            return positionData->numKeys;
        }
    } else if (channel == 1 && percentData) {
        return percentData->numKeys;
    }
    return 0;
}

KeyType NiPathInterpolator::GetKeyType(std::uint16_t channel) const
{
    if (channel == 0) {
        if (positionData) {
            return positionData->type;
        }
    } else if (channel == 1 && percentData) {
        return percentData->type;
    }
    return KeyType::kNoInterp;
}

KeyContent NiPathInterpolator::GetKeyContent(std::uint16_t channel) const
{
    if (channel == 0) {
        return KeyContent::kPos;
    }
    return channel == 1 ? KeyContent::kFloat : KeyContent::kTotal;
}

void* NiPathInterpolator::GetKeyArray(std::uint16_t channel) const
{
    if (channel == 0) {
        if (positionData) {
            return positionData->keys;
        }
    } else if (channel == 1 && percentData) {
        return percentData->keys;
    }
    return nullptr;
}

std::uint8_t NiPathInterpolator::GetKeyStride(std::uint16_t channel) const
{
    if (channel == 0) {
        if (positionData) {
            return positionData->keySize;
        }
    } else if (channel == 1 && percentData) {
        return percentData->keySize;
    }
    return 0;
}

void NiPathInterpolator::GuaranteeTimeRange(float start, float end)
{
    if (percentData) {
        return GuaranteeFloatTimeRange(percentData, start, end);
    }
}

void NiPathInterpolator::ProcessClone(NiCloningProcess& cloning)
{
    NiObject::ProcessClone(cloning);
    if (positionData) {
        positionData->ProcessClone(cloning);
    }
    if (percentData) {
        percentData->ProcessClone(cloning);
    }
}
