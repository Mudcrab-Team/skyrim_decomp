// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Base1f2bd0, String1f2bd0, Unit1f2bd0, Length, data, text, Differs1f2bd0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Base1f2bd0
{
    virtual ~Base1f2bd0();
};

struct String1f2bd0
{
    const char* data;  // 00

    std::uint32_t Length() const;
};

struct Unit1f2bd0 : Base1f2bd0
{
    String1f2bd0 text;  // 08

    bool Differs1f2bd0(const Base1f2bd0* a_other) const;  // compared: 0x1f2bd0
};
static_assert(offsetof(Unit1f2bd0, text) == 0x08, "Unit1f2bd0::text offset");
