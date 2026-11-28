// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Lock1b3060, Owner1b3060, Obj1b3060, UnlockA, UnlockB: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Lock1b3060
{
    void UnlockA();
    void UnlockB();
};

struct Owner1b3060
{
    std::uint8_t unk00[0x430];  // 000
    Lock1b3060* lock430;        // 430
};

struct Obj1b3060
{
    ~Obj1b3060();  // compared: 0x1b3060

    Owner1b3060* owner00;  // 00
    std::uint32_t mode08;  // 08
};
