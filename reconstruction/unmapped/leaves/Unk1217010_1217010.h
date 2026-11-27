// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk1217010, Unk1217010::Function1217010: GUESS(low)
// Unk1217010::unk00: OBSERVED
#pragma once

#include <cstdint>
#include <cstddef>

class Unk1217010
{
public:
    std::uint32_t Function1217010();
    std::uint32_t unk00;
};

static_assert(offsetof(Unk1217010, unk00) == 0, "field offset");
