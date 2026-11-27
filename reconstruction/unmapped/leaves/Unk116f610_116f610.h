// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk116f610: STANDIN GUESS(low)
// Unk116f610::Function116f610: GUESS(low)
// Unk116f610::linked, Unk116f610::local, LinkedState116f610: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct LinkedState116f610 { std::uint8_t unknown00[32]; void* value; };

class Unk116f610
{
public:
    void* Function116f610();
    LinkedState116f610* linked;
    std::uint8_t unknown8[8];
    void* local;
};
static_assert(offsetof(Unk116f610, linked) == 0, "field offset");
static_assert(offsetof(Unk116f610, local) == 16, "field offset");
