// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// Adapted bodies: none
// 0x1868e0 ExtraGuardedRefData::Function1868e0
// 0x186a90 ExtraGuardedRefData::Function186a90
#include "ExtraGuardedRefData_1868e0.h"

// At: GUESS(low)
template <class T>
static T& At(const void* a_base, std::uint32_t a_offset)
{
    return *reinterpret_cast<T*>(const_cast<char*>(static_cast<const char*>(a_base)) + a_offset);
}

bool ExtraGuardedRefData::Function1868e0() const
{
    return At<std::int32_t>(this, 0x20) == 0;
}

bool ExtraGuardedRefData::Function186a90(const std::int32_t* a_other) const
{
    return At<std::int32_t>(this, 0) == *a_other;
}
