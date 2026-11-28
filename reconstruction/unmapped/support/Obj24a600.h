// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Entry24a600, Obj24a600, Lookup, key, value, g_entries24a600, g_entryCount: GUESS(low)
#pragma once

#include <cstdint>

struct Entry24a600
{
    std::uint64_t key;    // 00
    std::uint64_t unk08;  // 08
    std::uint32_t value;  // 10
    std::uint32_t unk14;  // 14
    std::uint64_t unk18;  // 18
};

extern Entry24a600* g_entries24a600;
extern std::uint32_t g_entryCount;

class Obj24a600
{
public:
    bool Lookup(std::uint32_t* outValue) const;

    std::uint64_t key;  // 00
};
