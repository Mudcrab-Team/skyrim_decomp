// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// Adapted bodies: none
// 0x4324d0 BSFaceGenKeyframeExclusive::Function4324d0
// 0x432570 BSFaceGenKeyframeExclusive::Function432570
// 0x4324b0 BSFaceGenKeyframeExclusive::Function4324b0
// 0x4324c0 BSFaceGenKeyframeExclusive::Function4324c0
#include "BSFaceGenKeyframeExclusive_4324d0.h"

// At: GUESS(low)
template <class T>
static T& At(const void* a_base, std::uint32_t a_offset)
{
    return *reinterpret_cast<T*>(const_cast<char*>(static_cast<const char*>(a_base)) + a_offset);
}

std::uint8_t BSFaceGenKeyframeExclusive::Function4324d0() const
{
    return At<std::uint8_t>(this, 0x10);
}

void BSFaceGenKeyframeExclusive::Function432570(std::uint8_t a_value)
{
    At<std::uint8_t>(this, 0x10) = a_value;
}

float BSFaceGenKeyframeExclusive::Function4324b0() const
{
    return At<float>(this, 0x14);
}

float BSFaceGenKeyframeExclusive::Function4324c0() const
{
    return At<float>(this, 0x14);
}
