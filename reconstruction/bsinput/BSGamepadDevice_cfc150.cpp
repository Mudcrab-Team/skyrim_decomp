// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// Adapted bodies: none
// 0xcfc150 BSGamepadDevice::IsEnabled
#include "BSGamepadDevice_cfc150.h"

// At: GUESS(low)
template <class T>
static T& At(const void* a_base, std::uint32_t a_offset)
{
    return *reinterpret_cast<T*>(const_cast<char*>(static_cast<const char*>(a_base)) + a_offset);
}

bool BSGamepadDevice::IsEnabled() const
{
    return At<std::uint8_t>(this, 0xcc) != 0 && At<std::int32_t>(this, 0xc8) != -1;
}
