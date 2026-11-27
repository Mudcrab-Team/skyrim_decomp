// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk159b400, Unk159b400::Function159b400: GUESS(low)
// Unk159b400::unk00: OBSERVED
#pragma once

#include <cstdint>
#include <cstddef>

class Unk159b400
{
public:
    std::uint64_t Function159b400();
    std::uint64_t unk00;
};

static_assert(offsetof(Unk159b400, unk00) == 0, "field offset");
