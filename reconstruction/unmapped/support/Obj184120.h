// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Node184120, Obj184120, IsNotEqual: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Node184120
{
    void* item;        // 00
    Node184120* next;  // 08
};

struct Obj184120
{
    bool IsNotEqual(const Obj184120* a_rhs) const;  // compared: 0x184120

    std::uint8_t unk00[0x10];  // 00
    Node184120 list10;         // 10
};
