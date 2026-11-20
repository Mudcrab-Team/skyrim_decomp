// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial key data and interpolator layouts follow the measured accesses and the cited declarations.
// NiQuaternionInterpolator, NiRotData: EXE_RTTI
// NiKeyBasedInterpolator: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// RegisterStreamables, SaveBinary, GetKeyCount, GetKeyType, GetKeyArray, GetKeyStride, GuaranteeTimeRange: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// pose, data, cachedKeyIndex, keyCount, keyArray, keyType, keyStride, padding14, SetPoseValue: GUESS(low)
#pragma once

#include "NiKeyBasedInterpolator.h"

// KeyType, kNoInterp: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
enum class KeyType : std::int32_t { kNoInterp = 0 };

class NiRotData : public NiObject
{
public:
    std::uint32_t keyCount;
    std::uint32_t padding14;
    void* keyArray;
    KeyType keyType;
    std::uint8_t keyStride;
};

// NiQuaternion, w, x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiQuaternion
{
public:
    float w;
    float x;
    float y;
    float z;
};
static_assert(sizeof(NiQuaternion) == 0x10, "quaternion size");

class NiQuaternionInterpolator : public NiKeyBasedInterpolator
{
public:
    bool RegisterStreamables(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
    void SetPoseValue(const NiQuaternion& value);
    std::uint32_t GetKeyCount(std::uint16_t) const;
    KeyType GetKeyType(std::uint16_t) const;
    void* GetKeyArray(std::uint16_t) const;
    std::uint8_t GetKeyStride(std::uint16_t) const;
    void GuaranteeTimeRange(float start, float end);

private:
    NiQuaternion pose;
    NiRotData* data;
    std::uint32_t cachedKeyIndex;
};
static_assert(sizeof(NiQuaternionInterpolator) == 0x38, "interpolator size");
