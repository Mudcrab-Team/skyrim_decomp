// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial key data and interpolator layouts follow the measured accesses and the cited declarations.
// NiBoolInterpolator, NiBoolData: EXE_RTTI
// NiKeyBasedInterpolator: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// RegisterStreamables, GetKeyCount, GetKeyType, GetKeyArray, GetKeyStride, GetChannelPosed, GuaranteeTimeRange: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// pose, data, cachedKeyIndex, keyCount, keyArray, keyType, keyStride, padding14, SetPoseValue: GUESS(low)
#pragma once

#include "NiKeyBasedInterpolator.h"

// KeyType, kNoInterp: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
enum class KeyType : std::int32_t { kNoInterp = 0 };

class NiBoolData : public NiObject
{
public:
    std::uint32_t keyCount;
    std::uint32_t padding14;
    void* keyArray;
    KeyType keyType;
    std::uint8_t keyStride;
};

class NiBoolInterpolator : public NiKeyBasedInterpolator
{
public:
    bool RegisterStreamables(NiStream& stream) override;
    NiBoolInterpolator(NiBoolData* keys);
    NiBoolInterpolator(bool value);
    void SetPoseValue(bool value);
    std::uint32_t GetKeyCount(std::uint16_t) const;
    KeyType GetKeyType(std::uint16_t) const;
    void* GetKeyArray(std::uint16_t) const;
    std::uint8_t GetKeyStride(std::uint16_t) const;
    bool GetChannelPosed(std::uint16_t) const;
    void GuaranteeTimeRange(float start, float end);

private:
    std::uint8_t pose;
    NiBoolData* data;
    std::uint32_t cachedKeyIndex;
};
static_assert(sizeof(NiBoolInterpolator) == 0x30, "interpolator size");
