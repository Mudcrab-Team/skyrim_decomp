// Source exposure: mixed (community headers and the pinned image listing).
// Code origin: existing unit plus original reconstruction of Functionf11850.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0xf119b0 NiFloatsExtraData::GetRTTI
// 0xf11850 NiFloatsExtraData::Functionf11850
#include "NiFloatsExtraData.h"

// NiRTTI_NiFloatsExtraData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
extern const NiRTTI NiRTTI_NiFloatsExtraData;

const NiRTTI* NiFloatsExtraData::GetRTTI() const
{
    return &NiRTTI_NiFloatsExtraData;
}

bool NiFloatsExtraData::Functionf11850(std::uint32_t a_index, float a_value)
{
    if (a_index < size) {
        value[a_index] = a_value;
        return true;
    }
    return false;
}
