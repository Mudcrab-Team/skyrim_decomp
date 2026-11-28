// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Inner188c40, Holder188c40, Obj188c40, CompareByteDE: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Inner188c40
{
    std::uint8_t unk00[0xDE];  // 00
    std::uint8_t valueDE;      // DE
};

struct Holder188c40
{
    Inner188c40* inner;  // 00
};

struct Obj188c40
{
    static std::int32_t CompareByteDE(const Holder188c40* const* a_lhs, const Holder188c40* const* a_rhs);  // compared: 0x188c40
};
