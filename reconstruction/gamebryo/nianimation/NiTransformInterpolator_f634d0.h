// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original partial declarations based on measured fields and cited interfaces.
// NiTransformInterpolator: EXE_RTTI
// RegisterStreamables, SaveBinary, GetKeyCount, GetKeyType, GetKeyContent, GetKeyArray, GetKeyStride, GuaranteeTimeRange: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// value, data: GUESS(low)
#pragma once

#include "NiKeyBasedInterpolator.h"

// NiPoint3, NiPoint3::x, ::y, ::z, NiQuaternion, NiQuaternion::w, ::x, ::y, ::z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiPoint3
{
public:
    float x;
    float y;
    float z;
};

class NiQuaternion
{
public:
    float w;
    float x;
    float y;
    float z;
};

// NiQuatTransform: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// translation, rotation, scale: GUESS(low); component types follow their measured layout.
class NiQuatTransform
{
public:
    NiPoint3 translation;
    NiQuaternion rotation;
    float scale;
};
static_assert(sizeof(NiQuatTransform) == 0x20, "quaternion transform size");

// KeyType, KeyContent, kNoInterp, kFloat, kPos, kRot, kTotal: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
enum class KeyType : std::int32_t { kNoInterp = 0 };
enum class KeyContent : std::int32_t { kFloat = 0, kPos = 1, kRot = 2, kTotal = 6 };

// NiTransformData: STANDIN EXE_RTTI
// Count, type, stride and pointer names follow the observed channel accesses.
class NiTransformData : public NiObject
{
public:
    std::uint16_t rotationCount;
    std::uint16_t translationCount;
    std::uint16_t scaleCount;
    std::uint16_t padding16;
    KeyType rotationType;
    KeyType translationType;
    KeyType scaleType;
    std::uint8_t rotationStride;
    std::uint8_t translationStride;
    std::uint8_t scaleStride;
    std::uint8_t padding27;
    void* rotationKeys;
    void* translationKeys;
    void* scaleKeys;
};

class NiTransformInterpolator : public NiKeyBasedInterpolator
{
public:
    bool RegisterStreamables(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
    std::uint32_t GetKeyCount(std::uint16_t channel) const;
    KeyType GetKeyType(std::uint16_t channel) const;
    KeyContent GetKeyContent(std::uint16_t channel) const;
    void* GetKeyArray(std::uint16_t channel) const;
    std::uint8_t GetKeyStride(std::uint16_t channel) const;
    void GuaranteeTimeRange(float start, float end);

private:
    NiQuatTransform value;
    NiTransformData* data;
};
