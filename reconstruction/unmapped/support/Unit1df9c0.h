// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// FixedString1df9c0, GenderModel1df9c0, Unit1df9c0, GetGenderModelName1df9c0, Length, data, Slot0, Slot1, Slot2, Slot3, GetModelName, path, unk10, unk00, models: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct FixedString1df9c0
{
    std::uint32_t Length() const;

    const char* data;  // 00
};

class GenderModel1df9c0
{
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual const char* GetModelName() const;

    FixedString1df9c0 path;    // 08
    std::uint8_t unk10[0x28];  // 10
};
static_assert(sizeof(GenderModel1df9c0) == 0x38, "GenderModel1df9c0 size");
static_assert(offsetof(GenderModel1df9c0, path) == 0x08, "GenderModel1df9c0::path offset");

struct Unit1df9c0
{
    std::uint64_t unk00;            // 00
    GenderModel1df9c0 models[2];    // 08

    const char* GetGenderModelName1df9c0(std::int32_t a_sex) const;  // compared: 0x1df9c0
};
static_assert(offsetof(Unit1df9c0, models) == 0x08, "Unit1df9c0::models offset");
