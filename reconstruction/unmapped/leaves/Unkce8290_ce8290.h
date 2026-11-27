// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unkce8290: STANDIN GUESS(low)
// Unkce8290::Functionce8290: GUESS(low)
// Unkce8290::value, WordValuece8290: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct WordValuece8290 { std::uint32_t value; };

class Unkce8290
{
public:
    bool Functionce8290(const WordValuece8290& other);
    std::uint32_t value;
};
static_assert(offsetof(Unkce8290, value) == 0, "field offset");
