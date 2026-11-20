// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial layouts follow the pinned field accesses and cited declarations.
// NiFloatsExtraData: EXE_RTTI
// NiFloatsExtraData::size, ::value: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SetValue, GetValue: GUESS(low)
#pragma once

#include "NiExtraData_ef9840.h"

class NiFloatsExtraData : public NiExtraData
{
public:
    bool SetValue(std::uint32_t index, float element);
    float GetValue(std::uint32_t index) const;

private:
    std::uint32_t size;
    float* value;
};
