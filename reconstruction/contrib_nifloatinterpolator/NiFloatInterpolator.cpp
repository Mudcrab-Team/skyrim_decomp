// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf61760 NiFloatInterpolator::IsFloatValueSupported
// 0xf61810 NiFloatInterpolator::GetKeyType
// Adapted bodies: none
#include "NiFloatInterpolator.h"

bool NiFloatInterpolator::IsFloatValueSupported() const
{
    return true;
}

KeyType NiFloatInterpolator::GetKeyType(std::uint16_t a_channel) const
{
    return KeyType::kNoInterp;
}
