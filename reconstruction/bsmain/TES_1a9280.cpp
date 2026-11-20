// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// Adapted bodies: none
// 0x1a9280 TES::Function1a9280
// 0x1aa2d0 TES::Function1aa2d0
// 0x1aa2e0 TES::Function1aa2e0
// 0x1a2610 TES::Function1a2610
#include "TES_1a9280.h"

// At: GUESS(low)
template <class T>
static T& At(const void* a_base, std::uint32_t a_offset)
{
    return *reinterpret_cast<T*>(const_cast<char*>(static_cast<const char*>(a_base)) + a_offset);
}

void TES::Function1a9280(std::uint8_t a_value)
{
    At<std::uint8_t>(this, 0x13c) = a_value;
}

void TES::Function1aa2d0()
{
    ++At<std::uint32_t>(this, 0x2a8);
}

void TES::Function1aa2e0()
{
    --At<std::uint32_t>(this, 0x2a8);
}

void* TES::Function1a2610() const
{
    return At<void*>(this, 0x148);
}
