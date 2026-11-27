// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk156b750: STANDIN GUESS(low)
// Unk156b750::Function156b750: GUESS(low)
// Unk156b750::data, AllocationPrefix156b750: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct AllocationPrefix156b750 { std::uint32_t count; std::uint32_t unknown04; };

class Unk156b750
{
public:
    std::uint32_t Function156b750();
    std::uint8_t* data;
};
static_assert(offsetof(Unk156b750, data) == 0, "field offset");
