// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk7252c0: STANDIN GUESS(low)
// Unk7252c0::Function7252c0: GUESS(low)
// Unk7252c0::object, ValueObject7252c0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct ValueObject7252c0 { std::uint8_t unknown00[744]; std::uint32_t value; };

class Unk7252c0
{
public:
    std::uint32_t Function7252c0();
    std::uint8_t unknown0[8];
    ValueObject7252c0* object;
};
static_assert(offsetof(Unk7252c0, object) == 8, "field offset");
