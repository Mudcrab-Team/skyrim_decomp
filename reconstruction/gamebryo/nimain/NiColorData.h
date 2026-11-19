// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Base form: shared header declarations/NiObject.h for NiObject.
// NiColorData, NiColorData::~NiColorData, NiColorData::GetRTTI, NiColorData::LoadBinary, NiColorData::SaveBinary, NiColorData::IsEqual: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown10: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include "declarations/NiObject.h"

class NiColorData : public NiObject
{
public:
    // noinline: the deleting destructor must call the out-of-line destructor
    virtual __declspec(noinline) ~NiColorData();  // compared: 0x2a8d70  // slot 00
    const NiRTTI* GetRTTI() const override;  // 02
    void LoadBinary(NiStream& a_stream) override;  // 18
    void SaveBinary(NiStream& a_stream) override;  // 1B
    bool IsEqual(NiObject* a_object) override;  // 1C
    NiColorData();

    std::uint64_t unknown10;  // 10
    std::uint64_t unknown18;  // 18
    std::uint64_t unknown20;  // 20
};
static_assert(sizeof(NiColorData) == 0x28, "NiColorData size");
