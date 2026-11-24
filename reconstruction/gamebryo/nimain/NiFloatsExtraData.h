// Source exposure: mixed (community headers and the pinned image).
// Code origin: existing unit plus original reconstruction of SetValue and Functionf11870.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiFloatsExtraData, GetRTTI, size, value: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// Functionf11870, pad1C: GUESS(low)
// NiFloatsExtraData::SetValue: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(tesv-2013-map)
#pragma once

#include <cstdint>
#include <cstddef>
#include "NiExtraData.h"

class NiFloatsExtraData : public NiExtraData
{
public:
    virtual const NiRTTI* GetRTTI() const;  // compared: 0xf119b0
    bool SetValue(std::uint32_t a_index, float a_value);
    float Functionf11870(std::uint32_t a_index) const;

    std::uint32_t size;  // 18
    std::uint32_t pad1C;  // 1C
    float* value;  // 20
};
static_assert(sizeof(NiFloatsExtraData) == 0x28, "NiFloatsExtraData size");
