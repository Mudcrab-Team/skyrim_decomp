// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Node184980, Obj184980, IsNotEqual: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Node184980
{
    void* item;        // 00
    Node184980* next;  // 08
};

struct Obj184980
{
    bool IsNotEqual(const Obj184980* a_rhs) const;  // compared: 0x184980

    std::uint8_t unk00[0x10];  // 00
    Node184980 list10;         // 10
};
