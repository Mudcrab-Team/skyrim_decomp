// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// NiFloatData, NiFloatData::~NiFloatData, NiFloatData::GetRTTI, NiFloatData::LoadBinary, NiFloatData::SaveBinary, NiFloatData::IsEqual, NiFloatData::numKeys, NiFloatData::keys, NiFloatData::keySize, NiFloatData::type, NiFloatKey: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiFloatData::unknown14, NiFloatData::unknown25, NiFloatData::unknown26: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include "declarations/NiObject.h"

class NiFloatKey;

class NiFloatData : public NiObject
{
public:
    virtual ~NiFloatData();  // compared: 0x2a8db0  // slot 00
    const NiRTTI* GetRTTI() const override;  // 02
    void LoadBinary(NiStream& a_stream) override;  // 18
    void SaveBinary(NiStream& a_stream) override;  // 1B
    bool IsEqual(NiObject* a_object) override;  // 1C
    NiFloatData();

    std::uint32_t numKeys;  // 10
    std::uint32_t unknown14;  // 14
    NiFloatKey* keys;  // 18
    std::uint32_t type;  // 20
    std::uint8_t keySize;  // 24
    std::uint8_t unknown25;  // 25
    std::uint16_t unknown26;  // 26
};
static_assert(offsetof(NiFloatData, numKeys) == 0x10, "NiFloatData numKeys offset");
static_assert(offsetof(NiFloatData, keys) == 0x18, "NiFloatData keys offset");
static_assert(sizeof(NiFloatData) == 0x28, "NiFloatData size");
