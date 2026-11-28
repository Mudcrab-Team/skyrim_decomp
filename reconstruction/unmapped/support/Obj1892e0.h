// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Payload1892e0, Obj1892e0, IsNotEqual: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Payload1892e0
{
    std::uint64_t unk00;  // 00
    std::uint64_t unk08;  // 08
    std::uint32_t unk10;  // 10
};

struct Obj1892e0
{
    bool IsNotEqual(const Obj1892e0* a_other) const;  // compared: 0x1892e0

    std::uint64_t unk00;     // 00
    std::uint64_t unk08;     // 08
    Payload1892e0 payload;   // 10
};
