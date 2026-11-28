// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Base1ae4e0, Obj1ae4e0, GetDefault1ae4e0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

void* GetDefault1ae4e0();

struct Base1ae4e0
{
    Base1ae4e0(void* a_arg);

    void* ptr00;  // 00
};

struct Obj1ae4e0 : Base1ae4e0
{
    Obj1ae4e0();  // compared: 0x1ae4e0

    std::uint32_t unk08;  // 08
    std::uint32_t unk0C;  // 0C
    std::uint64_t unk10;  // 10
    std::uint8_t unk18;   // 18
};
