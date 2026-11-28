// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Pair139790: GUESS(low)
#pragma once

#include <cstdint>
#include <vector>

struct Pair139790
{
    ~Pair139790();

    std::uint64_t unk00[5];
    std::vector<void*> items;
};
