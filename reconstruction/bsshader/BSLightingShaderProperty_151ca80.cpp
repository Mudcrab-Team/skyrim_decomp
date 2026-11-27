// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x151ca80 BSLightingShaderProperty::AcceptsEffectData
// Adapted bodies: none
#include "BSLightingShaderProperty_151ca80.h"

bool BSLightingShaderProperty::AcceptsEffectData() const
{
    const std::uint64_t kSkipMask = 0x8000;
    const std::uint64_t word = flags;
    bool accepts = true;
    if ((word & kSkipMask) > 0 || (word & 0x4) > 0) {
        accepts = false;
    }
    return accepts;
}
