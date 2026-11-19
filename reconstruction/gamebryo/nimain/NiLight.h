// Source exposure: mixed (community declarations and the contributor-owned pack).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiLight, NiLight::~NiLight, NiLight::GetRTTI, NiLight::LoadBinary, NiLight::SaveBinary, NiLight::IsEqual: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown110: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include "declarations/NiAVObject.h"

class NiLight : public NiAVObject
{
public:
    virtual ~NiLight();  // compared: 0xeed200  // slot 00
    const NiRTTI* GetRTTI() const override;  // 02
    void LoadBinary(NiStream& a_stream) override;  // 18
    void SaveBinary(NiStream& a_stream) override;  // 1B
    bool IsEqual(NiObject* a_object) override;  // 1C
    NiLight();

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown110[0x30];  // 110
};
static_assert(sizeof(NiLight) == 0x140, "NiLight size");
