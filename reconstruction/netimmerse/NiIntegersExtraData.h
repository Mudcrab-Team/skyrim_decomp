// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// NiIntegersExtraData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiIntegersExtraData::GetRTTI: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown18: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include "../netimmerse/NiExtraData.h"

class NiIntegersExtraData : public NiExtraData
{
public:
    virtual const NiRTTI* GetRTTI() const;  // compared: 0xf12b50

    // members: padding kept; only GetRTTI is compared
    std::uint8_t unknown18[0x10];  // 18
};
static_assert(sizeof(NiIntegersExtraData) == 0x28, "NiIntegersExtraData size");
