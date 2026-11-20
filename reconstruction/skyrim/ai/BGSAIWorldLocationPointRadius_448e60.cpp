// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// Adapted bodies: none
// 0x448e60 BGSAIWorldLocationPointRadius::Function448e60
// 0x448ed0 BGSAIWorldLocationPointRadius::Function448ed0
#include "BGSAIWorldLocationPointRadius_448e60.h"

// At: GUESS(low)
template <class T>
static T& At(const void* a_base, std::uint32_t a_offset)
{
    return *reinterpret_cast<T*>(const_cast<char*>(static_cast<const char*>(a_base)) + a_offset);
}

std::uint8_t BGSAIWorldLocationPointRadius::Function448e60() const
{
    return At<std::uint8_t>(this, 0x30);
}

std::uint8_t BGSAIWorldLocationPointRadius::Function448ed0() const
{
    return At<std::uint8_t>(this, 0x31);
}
