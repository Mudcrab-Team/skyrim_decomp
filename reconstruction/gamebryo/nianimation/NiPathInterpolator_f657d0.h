// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: the key track views follow the pinned accesses and the public interpolation interfaces.
// NiPathInterpolator: EXE_RTTI
// NiKeyBasedInterpolator, NiCloningProcess: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetKeyCount, GetKeyType, GetKeyContent, GetKeyArray, GetKeyStride, GuaranteeTimeRange, ProcessClone: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// positionData, percentData, padding: GUESS(low)
#pragma once

#include <cstdint>
#include "NiKeyBasedInterpolator.h"

// KeyType, KeyContent, kNoInterp, kFloat, kPos, kTotal: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
enum class KeyContent : std::int32_t { kFloat = 0, kPos = 1, kTotal = 6 };
enum class KeyType : std::int32_t { kNoInterp = 0 };

// TrackKeyData: STANDIN GUESS(low); count, key pointer, type, and stride are used by the channel methods.
class TrackKeyData : public NiObject
{
public:
    std::uint32_t numKeys;
    std::uint32_t padding14;
    void* keys;
    KeyType type;
    std::uint8_t keySize;
};

class NiPathInterpolator : public NiKeyBasedInterpolator
{
public:
    std::uint32_t GetKeyCount(std::uint16_t channel) const;
    KeyType GetKeyType(std::uint16_t channel) const;
    KeyContent GetKeyContent(std::uint16_t channel) const;
    void* GetKeyArray(std::uint16_t channel) const;
    std::uint8_t GetKeyStride(std::uint16_t channel) const;
    void GuaranteeTimeRange(float start, float end);
    void ProcessClone(NiCloningProcess& cloning) override;

private:
    std::uint8_t padding18[0x10];
    TrackKeyData* positionData;
    TrackKeyData* percentData;
};
