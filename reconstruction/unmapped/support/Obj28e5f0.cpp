// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj28e5f0::Function28e5f0, treated as adapted: shaped like EffectSettingData byte swap in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00400000_o2.cpp:14959
// SPDX-License-Identifier: CC0-1.0
// 0x28e5f0 Obj28e5f0::Function28e5f0
#include "Obj28e5f0.h"

#include <intrin.h>

namespace
{
    void SwapEndian32(std::uint32_t& a_value)
    {
        // reverse byte order of serialized 32-bit field
        a_value = _byteswap_ulong(a_value);
    }
}

// Byte-swaps the twenty serialized 32-bit fields in place for endian conversion.
void Obj28e5f0::Function28e5f0()
{
    SwapEndian32(field04);
    SwapEndian32(field08);
    SwapEndian32(field10);
    SwapEndian32(field24);
    SwapEndian32(field28);
    SwapEndian32(field2C);
    SwapEndian32(field30);
    SwapEndian32(field34);
    SwapEndian32(field38);
    SwapEndian32(field3C);
    SwapEndian32(field40);
    SwapEndian32(field44);
    SwapEndian32(field4C);
    SwapEndian32(field50);
    SwapEndian32(field54);
    SwapEndian32(field58);
    SwapEndian32(field5C);
    SwapEndian32(field60);
    SwapEndian32(field64);
    SwapEndian32(field68);
}
