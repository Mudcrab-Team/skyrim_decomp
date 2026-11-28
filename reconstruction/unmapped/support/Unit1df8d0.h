// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// FixedString1df8d0, GenderModel1df8d0, Unit1df8d0, GetGenderModel1df8d0, Length, data, unk00, path, unk10, models: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct FixedString1df8d0
{
    std::uint32_t Length() const;

    const char* data;  // 00
};

struct GenderModel1df8d0
{
    std::uint64_t unk00;        // 00
    FixedString1df8d0 path;     // 08
    std::uint8_t unk10[0x28];   // 10
};
static_assert(sizeof(GenderModel1df8d0) == 0x38, "GenderModel1df8d0 size");
static_assert(offsetof(GenderModel1df8d0, path) == 0x08, "GenderModel1df8d0::path offset");

struct Unit1df8d0
{
    std::uint64_t unk00;            // 00
    GenderModel1df8d0 models[2];    // 08

    GenderModel1df8d0* GetGenderModel1df8d0(std::int32_t a_sex);  // compared: 0x1df8d0
};
static_assert(offsetof(Unit1df8d0, models) == 0x08, "Unit1df8d0::models offset");
