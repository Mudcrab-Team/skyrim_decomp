// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk7233f0: STANDIN GUESS(low)
// Unk7233f0::Function7233f0: GUESS(low)
// Unk7233f0::object, FloatObject7233f0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct FloatObject7233f0 { std::uint8_t unknown00[184]; float value; };

class Unk7233f0
{
public:
    void Function7233f0(float value);
    std::uint8_t unknown0[8];
    FloatObject7233f0* object;
};
static_assert(offsetof(Unk7233f0, object) == 8, "field offset");
