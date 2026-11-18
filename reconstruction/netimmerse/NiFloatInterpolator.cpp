// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
// 0xf617d0 NiFloatInterpolator::GetKeyCount
// 0xf617f0 NiFloatInterpolator::GetKeyContent
// 0xf61980 NiFloatInterpolator::GuaranteeTimeRange
// 0xf61820 NiFloatInterpolator::GetKeyArray
// 0xf61840 NiFloatInterpolator::GetKeyStride
// 0xf61860 NiFloatInterpolator::GetChannelPosed
#include "NiFloatInterpolator.h"

std::uint32_t NiFloatInterpolator::GetKeyCount(std::uint16_t a_channel) const
{
    if (unk20 == nullptr) {
        return 0;
    }
    return unk20->keyCount;
}

KeyContent NiFloatInterpolator::GetKeyContent(std::uint16_t a_channel) const
{
    if (unk20 == nullptr) {
        return static_cast<KeyContent>(0);
    }
    return unk20->keyContent;
}

void NiFloatInterpolator::GuaranteeTimeRange(float a_start, float a_end)
{
    if (unk20 == nullptr) {
        return;
    }
    GuaranteeFloatTimeRange(unk20, a_start, a_end);
}

void* NiFloatInterpolator::GetKeyArray(std::uint16_t a_channel) const
{
    if (unk20 == nullptr) {
        return nullptr;
    }
    return unk20->keyArray;
}

std::uint8_t NiFloatInterpolator::GetKeyStride(std::uint16_t a_channel) const
{
    if (unk20 == nullptr) {
        return 0;
    }
    return unk20->keyStride;
}

bool NiFloatInterpolator::GetChannelPosed(std::uint16_t a_channel) const
{
    return unk20 == nullptr && -3.4028234663852886e+38f != unk18;
}
