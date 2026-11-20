// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// Adapted bodies: none
// 0xec1850 BSCounterStorage::Functionec1850
// 0xec1860 BSCounterStorage::Functionec1860
#include "BSCounterStorage_ec1850.h"

// At: GUESS(low)
template <class T>
static T& At(const void* a_base, std::uint32_t a_offset)
{
    return *reinterpret_cast<T*>(const_cast<char*>(static_cast<const char*>(a_base)) + a_offset);
}

std::uint32_t BSCounterStorage::Functionec1850() const
{
    return At<std::uint32_t>(this, 0x20);
}

std::uint32_t BSCounterStorage::Functionec1860() const
{
    return At<std::uint32_t>(this, 0x24);
}
