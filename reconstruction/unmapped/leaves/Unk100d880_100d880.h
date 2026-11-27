// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk100d880: STANDIN GUESS(low)
// Unk100d880::Function100d880: GUESS(low)
// SharedCounter100d880: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include <intrin.h>

struct SharedCounter100d880 { std::uint64_t unknown00; volatile long count; };

class Unk100d880
{
public:
    void Function100d880(SharedCounter100d880* value);
};
