// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using cited declarations and stand-in layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0xcfe280 GString::Clear
#include "GString_cfe280.h"

// Resets the string to the shared empty descriptor while preserving its heap type flags.
void GString::Clear()
{
    NullData.AddRef();
    DataDesc* old = reinterpret_cast<DataDesc*>(bits & ~std::uintptr_t(3));
    old->Release();
    std::uint32_t heapType = static_cast<std::uint32_t>(bits) & 3;
    bits = reinterpret_cast<std::uintptr_t>(&NullData) | heapType;
}
