// Source exposure: mixed (local binary analysis and public names).
// Code origin: existing leaf plus original reconstruction of keyframe accessors.
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x432500 BSFaceGenKeyframeExclusive::Unk_0D
// 0x4324b0 BSFaceGenKeyframeExclusive::Function4324b0
// 0x4324c0 BSFaceGenKeyframeExclusive::Function4324c0
// 0x4324d0 BSFaceGenKeyframeExclusive::Function4324d0
// 0x432570 BSFaceGenKeyframeExclusive::Function432570
#include "BSFaceGenKeyframeExclusive.h"

std::uint8_t BSFaceGenKeyframeExclusive::Unk_0D() const
{
    return 0x1;
}

float BSFaceGenKeyframeExclusive::Function4324b0() const
{
    return field14;
}

float BSFaceGenKeyframeExclusive::Function4324c0() const
{
    return field14;
}

std::uint8_t BSFaceGenKeyframeExclusive::Function4324d0() const
{
    return field10;
}

void BSFaceGenKeyframeExclusive::Function432570(std::uint8_t a_value)
{
    field10 = a_value;
}
