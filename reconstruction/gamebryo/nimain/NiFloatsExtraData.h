// Source exposure: mixed (community headers and the pinned image).
// Code origin: existing unit plus original reconstruction of Functionf11850.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiFloatsExtraData, GetRTTI, size, value: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// Functionf11850, pad1C: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include "NiExtraData.h"

class NiFloatsExtraData : public NiExtraData
{
public:
    virtual const NiRTTI* GetRTTI() const;  // compared: 0xf119b0
    bool Functionf11850(std::uint32_t a_index, float a_value);

    std::uint32_t size;  // 18
    std::uint32_t pad1C;  // 1C
    float* value;  // 20
};
static_assert(sizeof(NiFloatsExtraData) == 0x28, "NiFloatsExtraData size");
