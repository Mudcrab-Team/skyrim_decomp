// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSAnimNote: STANDIN EXE_RTTI
// BSAnimNote::Functionf8a810: GUESS(low)
// BSAnimNote::storedValue: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>



class BSAnimNote
{
public:
    bool Functionf8a810(const std::uint32_t& value);
    std::uint8_t unknown0[20];
    std::uint32_t storedValue;
};
static_assert(offsetof(BSAnimNote, storedValue) == 20, "field offset");
