// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj28e5f0::Function28e5f0, treated as adapted: shaped like EffectSettingData byte swap in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00400000_o2.cpp:14959
// SPDX-License-Identifier: CC0-1.0
// Obj28e5f0, Obj28e5f0::Function28e5f0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class Obj28e5f0
{
public:
    void Function28e5f0();

    std::uint32_t unk00;       // 0x00
    std::uint32_t field04;     // 0x04
    std::uint32_t field08;     // 0x08
    std::uint32_t unk0C;       // 0x0C
    std::uint32_t field10;     // 0x10
    std::uint8_t unk14[0x10];  // 0x14
    std::uint32_t field24;     // 0x24
    std::uint32_t field28;     // 0x28
    std::uint32_t field2C;     // 0x2C
    std::uint32_t field30;     // 0x30
    std::uint32_t field34;     // 0x34
    std::uint32_t field38;     // 0x38
    std::uint32_t field3C;     // 0x3C
    std::uint32_t field40;     // 0x40
    std::uint32_t field44;     // 0x44
    std::uint32_t unk48;       // 0x48
    std::uint32_t field4C;     // 0x4C
    std::uint32_t field50;     // 0x50
    std::uint32_t field54;     // 0x54
    std::uint32_t field58;     // 0x58
    std::uint32_t field5C;     // 0x5C
    std::uint32_t field60;     // 0x60
    std::uint32_t field64;     // 0x64
    std::uint32_t field68;     // 0x68
};

static_assert(offsetof(Obj28e5f0, field04) == 0x04, "field04 offset");
static_assert(offsetof(Obj28e5f0, field24) == 0x24, "field24 offset");
static_assert(offsetof(Obj28e5f0, field4C) == 0x4C, "field4C offset");
static_assert(offsetof(Obj28e5f0, field68) == 0x68, "field68 offset");
