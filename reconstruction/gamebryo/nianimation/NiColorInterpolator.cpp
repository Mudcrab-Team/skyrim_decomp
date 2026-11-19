// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Code origin: original; the listing and community declarations only
// Adapted bodies: none (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
// 0xf62970 NiColorInterpolator::GetKeyType
// 0xf62d80 NiColorInterpolator::GetRTTI
// 0xf62930 NiColorInterpolator::GetKeyCount
// 0xf62950 NiColorInterpolator::GetKeyContent
// 0xf62b50 NiColorInterpolator::GuaranteeTimeRange
// 0xf62980 NiColorInterpolator::GetKeyArray
// 0xf629a0 NiColorInterpolator::GetKeyStride
// 0xf628c0 NiColorInterpolator::IsColorAValueSupported
#include "NiColorInterpolator.h"

const NiRTTI NiRTTI_NiColorInterpolator{};
void GuaranteeTimeRangeImpl(NiColorKeyData*, float, float);

// TODO body: RVA 0xf62970, 6 bytes, NiColorInterpolator::GetKeyType.
KeyType NiColorInterpolator::GetKeyType(std::uint16_t a_channel) const
{
    return static_cast<KeyType>(3);
}

// TODO body: RVA 0xf62d80, 8 bytes, NiColorInterpolator::GetRTTI.
const NiRTTI* NiColorInterpolator::GetRTTI() const
{
    return &NiRTTI_NiColorInterpolator;
}

// TODO body: RVA 0xf62930, 14 bytes, NiColorInterpolator::GetKeyCount.
std::uint32_t NiColorInterpolator::GetKeyCount(std::uint16_t a_channel) const
{
    if (!keyData) {
        return 0;
    }
    return keyData->keyCount;
}

// TODO body: RVA 0xf62950, 14 bytes, NiColorInterpolator::GetKeyContent.
KeyContent NiColorInterpolator::GetKeyContent(std::uint16_t a_channel) const
{
    if (!keyData) {
        return static_cast<KeyContent>(0);
    }
    return keyData->keyContent;
}

// TODO body: RVA 0xf62b50, 14 bytes, NiColorInterpolator::GuaranteeTimeRange.
void NiColorInterpolator::GuaranteeTimeRange(float a_start, float a_end)
{
    if (keyData) {
        return GuaranteeTimeRangeImpl(keyData, a_start, a_end);
    }
}

// TODO body: RVA 0xf62980, 15 bytes, NiColorInterpolator::GetKeyArray.
void* NiColorInterpolator::GetKeyArray(std::uint16_t a_channel) const
{
    if (!keyData) {
        return nullptr;
    }
    return keyData->keyArray;
}

// TODO body: RVA 0xf629a0, 15 bytes, NiColorInterpolator::GetKeyStride.
std::uint8_t NiColorInterpolator::GetKeyStride(std::uint16_t a_channel) const
{
    if (!keyData) {
        return 0;
    }
    return keyData->keyStride;
}

std::uint8_t NiColorInterpolator::IsColorAValueSupported() const
{
    return 0x1;
}
