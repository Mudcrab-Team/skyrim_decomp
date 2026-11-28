// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// FixedString1df920, GenderIcon1df920, Unit1df920, GetGenderIconPath1df920, Length, data, path, unk08, unk00, icons: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct FixedString1df920
{
    std::uint32_t Length() const;

    const char* data;  // 00
};

struct GenderIcon1df920
{
    FixedString1df920 path;  // 00
    std::uint64_t unk08;     // 08
};
static_assert(sizeof(GenderIcon1df920) == 0x10, "GenderIcon1df920 size");

struct Unit1df920
{
    std::uint8_t unk00[0x80];    // 00
    GenderIcon1df920 icons[2];   // 80

    const char* GetGenderIconPath1df920(std::int32_t a_sex) const;  // compared: 0x1df920
};
static_assert(offsetof(Unit1df920, icons) == 0x80, "Unit1df920::icons offset");
