// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiFloatsExtraData: EXE_RTTI
// NiFloatsExtraData::size, NiFloatsExtraData::value: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CopyMembers, SetValue, GetValue, AllocateExtraData: GUESS(low)
#pragma once

#include "NiExtraData_ef9840.h"

class NiFloatsExtraData : public NiExtraData
{
public:
    void CopyMembers(NiFloatsExtraData* dest);
    bool SetValue(std::uint32_t index, float element);
    float GetValue(std::uint32_t index) const;

private:
    std::uint32_t size;
    float* value;
};
