// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x431d20 BSFaceGenKeyframeMultiple::Unk_08
// Adapted bodies: none
#include "BSFaceGenKeyframeMultiple_431d20.h"

float BSFaceGenKeyframeMultiple::Unk_08()
{
    float result = 0.0f;
    for (std::uint32_t i = 0; i < count; ++i) {
        if (Unk_0E(i)) {
            const float value = values[i];
            result = (value > result) ? value : result;
        }
    }
    return result;
}
