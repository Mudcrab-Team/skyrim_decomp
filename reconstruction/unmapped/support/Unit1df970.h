// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// FixedString1df970, GenderMessageIcon1df970, Unit1df970, GetGenderMessageIconPath1df970, Length, data, path, unk08, unk00, icons: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct FixedString1df970
{
    std::uint32_t Length() const;

    const char* data;  // 00
};

struct GenderMessageIcon1df970
{
    FixedString1df970 path;   // 00
    std::uint64_t unk08[2];   // 08
};
static_assert(sizeof(GenderMessageIcon1df970) == 0x18, "GenderMessageIcon1df970 size");

struct Unit1df970
{
    std::uint8_t unk00[0xA8];           // 00
    GenderMessageIcon1df970 icons[2];   // A8

    const char* GetGenderMessageIconPath1df970(std::int32_t a_sex) const;  // compared: 0x1df970
};
static_assert(offsetof(Unit1df970, icons) == 0xA8, "Unit1df970::icons offset");
