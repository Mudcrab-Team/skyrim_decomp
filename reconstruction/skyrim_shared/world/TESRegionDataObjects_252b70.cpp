// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// Adapted bodies: none
// 0x252b70 TESRegionDataObjects::Function252b70
// 0x252b90 TESRegionDataObjects::Function252b90
#include "TESRegionDataObjects_252b70.h"

// At: GUESS(low)
template <class T>
static T& At(const void* a_base, std::uint32_t a_offset)
{
    return *reinterpret_cast<T*>(const_cast<char*>(static_cast<const char*>(a_base)) + a_offset);
}

std::uint8_t TESRegionDataObjects::Function252b70() const
{
    return At<std::uint8_t>(this, 0x18);
}

void* TESRegionDataObjects::Function252b90() const
{
    return At<void*>(this, 0x10);
}
