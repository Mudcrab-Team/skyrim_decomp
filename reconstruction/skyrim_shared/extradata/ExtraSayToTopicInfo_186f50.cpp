// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// Adapted bodies: none
// 0x186f50 ExtraSayToTopicInfo::Function186f50
// 0x186f90 ExtraSayToTopicInfo::Function186f90
#include "ExtraSayToTopicInfo_186f50.h"

// At: GUESS(low)
template <class T>
static T& At(const void* a_base, std::uint32_t a_offset)
{
    return *reinterpret_cast<T*>(const_cast<char*>(static_cast<const char*>(a_base)) + a_offset);
}

void ExtraSayToTopicInfo::Function186f50(void* a_value)
{
    At<void*>(this, 0x10) = a_value;
}

void* ExtraSayToTopicInfo::Function186f90() const
{
    return At<void*>(this, 0x38);
}
