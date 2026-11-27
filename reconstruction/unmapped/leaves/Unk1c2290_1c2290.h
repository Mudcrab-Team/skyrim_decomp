// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk1c2290, Unk1c2290::Function1c2290: GUESS(low)
// Unk1c2290::unkda5: OBSERVED
// Unk1c2290::unknown00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unk1c2290
{
public:
    void Function1c2290(std::uint8_t value);
    std::uint8_t unknown00[3493];
    std::uint8_t unkda5;
};

static_assert(offsetof(Unk1c2290, unkda5) == 3493, "field offset");
