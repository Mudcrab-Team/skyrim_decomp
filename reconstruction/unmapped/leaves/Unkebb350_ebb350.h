// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unkebb350: STANDIN GUESS(low)
// Unkebb350::Functionebb350: GUESS(low)
// Unkebb350::state, JobStateebb350: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct JobStateebb350 { std::uint8_t unknown00[192]; std::uint32_t value; };

class Unkebb350
{
public:
    void Functionebb350(std::uint32_t value);
    JobStateebb350* state;
};
static_assert(offsetof(Unkebb350, state) == 0, "field offset");
