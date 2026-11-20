// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// Adapted bodies: none
// 0xcd6bf0 BSNullImplGameSound::Functioncd6bf0
#include "BSNullImplGameSound_cd6bf0.h"

// At: GUESS(low)
template <class T>
static T& At(const void* a_base, std::uint32_t a_offset)
{
    return *reinterpret_cast<T*>(const_cast<char*>(static_cast<const char*>(a_base)) + a_offset);
}

void BSNullImplGameSound::Functioncd6bf0()
{
    At<std::uint32_t>(this, 0x5c) &= ~0x60u;
}
