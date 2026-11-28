// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Entry24a450, Obj24a450, Lookup, key, value, g_tableReady, g_entries24a450, g_entryCount: GUESS(low)
#pragma once

#include <cstdint>

struct Entry24a450
{
    std::uint64_t key;    // 00
    std::uint64_t unk08;  // 08
    std::uint32_t value;  // 10
    std::uint32_t unk14;  // 14
    std::uint64_t unk18;  // 18
};

extern bool g_tableReady;
extern Entry24a450* g_entries24a450;
extern std::uint32_t g_entryCount;

class Obj24a450
{
public:
    bool Lookup(std::uint32_t* outValue) const;

    std::uint64_t key;  // 00
};
