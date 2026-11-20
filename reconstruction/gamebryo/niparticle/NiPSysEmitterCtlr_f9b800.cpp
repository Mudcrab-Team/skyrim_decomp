// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// Adapted bodies: none
// 0xf9b800 NiPSysEmitterCtlr::GetInterpolator
#include "NiPSysEmitterCtlr_f9b800.h"

// At: GUESS(low)
template <class T>
static T& At(const void* a_base, std::uint32_t a_offset)
{
    return *reinterpret_cast<T*>(const_cast<char*>(static_cast<const char*>(a_base)) + a_offset);
}

NiInterpolator* NiPSysEmitterCtlr::GetInterpolator(std::uint16_t a_index) const
{
    if (a_index == 0) {
        return At<NiInterpolator*>(this, 0x48);
    }
    if (a_index == 1) {
        return At<NiInterpolator*>(this, 0x60);
    }
    return nullptr;
}
