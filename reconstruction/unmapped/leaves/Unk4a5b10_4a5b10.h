// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk4a5b10, Unk4a5b10::Function4a5b10: GUESS(low)
// Unk4a5b10::unk00: OBSERVED
#pragma once

#include <cstdint>
#include <cstddef>

class Unk4a5b10
{
public:
    std::uint8_t Function4a5b10();
    std::uint8_t unk00;
};

static_assert(offsetof(Unk4a5b10, unk00) == 0, "field offset");
