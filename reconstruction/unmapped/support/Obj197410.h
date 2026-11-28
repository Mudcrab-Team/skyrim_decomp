// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Target197410, Obj197410, HasPositiveCount: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Target197410
{
    std::int32_t GetCount();
};

struct Obj197410
{
    bool HasPositiveCount(Target197410* a_target) const;  // compared: 0x197410
};
