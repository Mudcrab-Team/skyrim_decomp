// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// Adapted bodies: none
// 0x448e10 BGSAIWorldLocationPointRadius::Function448e10
// 0x449810 BGSAIWorldLocationPointRadius::Function449810
#include "BGSAIWorldLocationPointRadius_448e10.h"

// At: GUESS(low)
template <class T>
static T& At(const void* a_base, std::uint32_t a_offset)
{
    return *reinterpret_cast<T*>(const_cast<char*>(static_cast<const char*>(a_base)) + a_offset);
}

float BGSAIWorldLocationPointRadius::Function448e10() const
{
    return At<float>(this, 0x2c);
}

float BGSAIWorldLocationPointRadius::Function449810() const
{
    return At<float>(this, 0x28);
}
