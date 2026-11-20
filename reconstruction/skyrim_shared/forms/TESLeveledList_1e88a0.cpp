// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// Adapted bodies: none
// 0x1e88a0 TESLeveledList::Function1e88a0
// 0x1e88b0 TESLeveledList::Function1e88b0
#include "TESLeveledList_1e88a0.h"

// At: GUESS(low)
template <class T>
static T& At(const void* a_base, std::uint32_t a_offset)
{
    return *reinterpret_cast<T*>(const_cast<char*>(static_cast<const char*>(a_base)) + a_offset);
}

void TESLeveledList::Function1e88a0(std::uint8_t a_value)
{
    At<std::uint8_t>(this, 0x10) = a_value;
}

bool TESLeveledList::Function1e88b0() const
{
    return (At<std::uint8_t>(this, 0x11) & 1) != 0;
}
