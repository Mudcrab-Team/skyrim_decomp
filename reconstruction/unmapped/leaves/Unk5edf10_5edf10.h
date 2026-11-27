// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk5edf10: STANDIN GUESS(low)
// Unk5edf10::Function5edf10: GUESS(low)
// Unk5edf10::link, LinkedObject5edf10: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct LinkedObject5edf10 { void* value; };

class Unk5edf10
{
public:
    void* Function5edf10();
    std::uint8_t unknown0[64];
    LinkedObject5edf10* link;
};
static_assert(offsetof(Unk5edf10, link) == 64, "field offset");
