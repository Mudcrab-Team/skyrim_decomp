// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BGSWaterCollisionManager__BGSWaterUpdateI, BGSWaterCollisionManager__BGSWaterUpdateI::Function525000: GUESS(low)
// BGSWaterCollisionManager__BGSWaterUpdateI::unk38: OBSERVED
// BGSWaterCollisionManager__BGSWaterUpdateI::unknown00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BGSWaterCollisionManager__BGSWaterUpdateI
{
public:
    void Function525000(std::uint64_t value);
    std::uint8_t unknown00[56];
    std::uint64_t unk38;
};

static_assert(offsetof(BGSWaterCollisionManager__BGSWaterUpdateI, unk38) == 56, "field offset");
