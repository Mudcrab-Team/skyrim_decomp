// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Entry1cb640, Array1cb640, Target1cb640, Obj1cb640, FindValue: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Entry1cb640
{
    std::uint32_t id;     // 00
    std::uint32_t value;  // 04
    std::uint32_t unk08;  // 08
};

struct Array1cb640
{
    Entry1cb640* data;   // 00
    std::uint64_t unk08; // 08
    std::uint32_t size;  // 10
};

struct Target1cb640
{
    std::uint8_t unk00[0x14];  // 00
    std::uint32_t id14;        // 14
};

struct Obj1cb640
{
    std::uint32_t FindValue(const Target1cb640* a_target) const;  // compared: 0x1cb640

    std::uint8_t unk00[0x4C0];  // 000
    Array1cb640* array4C0;      // 4C0
};
