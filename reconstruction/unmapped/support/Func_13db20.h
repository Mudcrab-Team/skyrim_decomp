// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Entry13db20: GUESS(low)
// Func_13db20: GUESS(low)
#pragma once

#include <cstdint>
#include <vector>

struct Entry13db20
{
    std::uint64_t unk00[5];
    std::vector<void*> items;
    std::uint64_t unk40[3];
};

static_assert(sizeof(Entry13db20) == 0x58, "Entry13db20 size");

struct Func_13db20
{
    static void DestroyRange(Entry13db20* first, Entry13db20* last);
};
