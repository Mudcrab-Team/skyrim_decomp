// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2652d0::Function2652d0, treated as adapted: shaped like EffectSettingData byte swap in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00400000_o2.cpp:14959
// SPDX-License-Identifier: CC0-1.0
// Obj2652d0, Obj2652d0::Function2652d0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class Obj2652d0
{
public:
    void Function2652d0();

    std::uint32_t field00;  // 0x00
    std::uint32_t field04;  // 0x04
    std::uint32_t field08;  // 0x08
    std::uint32_t field0C;  // 0x0C
    std::uint64_t field10;  // 0x10
    std::uint64_t field18;  // 0x18
    std::uint32_t field20;  // 0x20
    std::uint32_t field24;  // 0x24
    std::uint32_t field28;  // 0x28
    std::uint32_t unk2C;    // 0x2C
    std::uint64_t field30;  // 0x30
    std::uint64_t field38;  // 0x38
    std::uint32_t field40;  // 0x40
    std::uint32_t field44;  // 0x44
    std::uint32_t field48;  // 0x48
    std::uint32_t unk4C;    // 0x4C
    std::uint64_t field50;  // 0x50
    std::uint64_t field58;  // 0x58
    std::uint64_t field60;  // 0x60
    std::uint32_t field68;  // 0x68
    std::uint32_t field6C;  // 0x6C
    std::uint32_t field70;  // 0x70
    std::uint32_t field74;  // 0x74
    std::uint64_t field78;  // 0x78
    std::uint64_t field80;  // 0x80
};

static_assert(offsetof(Obj2652d0, field10) == 0x10, "field10 offset");
static_assert(offsetof(Obj2652d0, field30) == 0x30, "field30 offset");
static_assert(offsetof(Obj2652d0, field50) == 0x50, "field50 offset");
static_assert(offsetof(Obj2652d0, field80) == 0x80, "field80 offset");
