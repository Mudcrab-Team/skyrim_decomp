// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// Adapted bodies: none
// 0x1e09f0 TESContainer::Function1e09f0
// 0x1e0a00 TESContainer::Function1e0a00
#include "TESContainer_1e09f0.h"

// At: GUESS(low)
template <class T>
static T& At(const void* a_base, std::uint32_t a_offset)
{
    return *reinterpret_cast<T*>(const_cast<char*>(static_cast<const char*>(a_base)) + a_offset);
}

void TESContainer::Function1e09f0(std::uint8_t a_value)
{
    At<std::uint8_t>(this, 0x14) = a_value;
}

std::uint8_t TESContainer::Function1e0a00() const
{
    return At<std::uint8_t>(this, 0x14);
}
