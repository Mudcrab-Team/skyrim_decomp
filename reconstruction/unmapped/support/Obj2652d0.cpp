// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2652d0::Function2652d0, treated as adapted: shaped like EffectSettingData byte swap in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00400000_o2.cpp:14959
// SPDX-License-Identifier: CC0-1.0
// 0x2652d0 Obj2652d0::Function2652d0
#include "Obj2652d0.h"

#include <intrin.h>

namespace
{
    void SwapEndian32(std::uint32_t& a_value)
    {
        // reverse byte order of serialized 32-bit field
        a_value = _byteswap_ulong(a_value);
    }

    void SwapEndian64(std::uint64_t& a_value)
    {
        // reverse byte order of serialized 64-bit field
        a_value = _byteswap_uint64(a_value);
    }
}

// Byte-swaps the serialized 32-bit and 64-bit record fields in place for endian conversion.
void Obj2652d0::Function2652d0()
{
    SwapEndian32(field00);
    SwapEndian32(field04);
    SwapEndian32(field08);
    SwapEndian32(field0C);
    SwapEndian32(field20);
    SwapEndian32(field24);
    SwapEndian32(field28);
    SwapEndian64(field10);
    SwapEndian64(field18);
    SwapEndian64(field30);
    SwapEndian64(field38);
    SwapEndian32(field40);
    SwapEndian32(field44);
    SwapEndian32(field48);
    SwapEndian64(field50);
    SwapEndian64(field58);
    SwapEndian64(field60);
    SwapEndian32(field68);
    SwapEndian32(field6C);
    SwapEndian32(field70);
    SwapEndian32(field74);
    SwapEndian64(field78);
    SwapEndian64(field80);
}
