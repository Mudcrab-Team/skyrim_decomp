// Recipe: reconstruction/recipes/o2-fpfast.json
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk430870: STANDIN GUESS(low)
// Unk430870::Function430870: GUESS(low)
// Unk430870::storedValue: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>



class Unk430870
{
public:
    bool Function430870(float value);
    std::uint8_t unknown0[12];
    float storedValue;
};
static_assert(offsetof(Unk430870, storedValue) == 12, "field offset");
