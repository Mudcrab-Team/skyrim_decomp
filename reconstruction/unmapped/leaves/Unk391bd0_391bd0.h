// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk391bd0: STANDIN GUESS(low)
// Unk391bd0::Function391bd0: GUESS(low)
// Unk391bd0::source, Unk391bd0::value, SourceByte391bd0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct SourceByte391bd0 { std::uint8_t unknown00[31]; std::int8_t value; };

class Unk391bd0
{
public:
    void Function391bd0();
    SourceByte391bd0* source;
    std::uint8_t unknown8[4];
    std::int32_t value;
};
static_assert(offsetof(Unk391bd0, source) == 0, "field offset");
static_assert(offsetof(Unk391bd0, value) == 12, "field offset");
