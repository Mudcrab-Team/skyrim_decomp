// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// Adapted bodies: none
// 0x190b00 TESFullName::Function190b00
// 0x190bd0 TESFullName::Function190bd0
#include "TESFullName_190b00.h"

// At: GUESS(low)
template <class T>
static T& At(const void* a_base, std::uint32_t a_offset)
{
    return *reinterpret_cast<T*>(const_cast<char*>(static_cast<const char*>(a_base)) + a_offset);
}

bool TESFullName::Function190b00() const
{
    return (At<std::uint8_t>(this, 0x10) & 1) != 0;
}

void TESFullName::Function190bd0(std::uint8_t a_value)
{
    At<std::uint16_t>(this, 0x12) = a_value;
}
