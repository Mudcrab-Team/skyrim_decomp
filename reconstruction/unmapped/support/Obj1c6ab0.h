// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// RefTarget1c6ab0, Obj1c6ab0, Assign: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct RefTarget1c6ab0
{
    virtual ~RefTarget1c6ab0();

    std::uint8_t unk08[0x08];  // 08
    long refCount10;           // 10
};

struct Obj1c6ab0
{
    Obj1c6ab0& Assign(const Obj1c6ab0& a_rhs);  // compared: 0x1c6ab0

    RefTarget1c6ab0* ptr;  // 00
};
