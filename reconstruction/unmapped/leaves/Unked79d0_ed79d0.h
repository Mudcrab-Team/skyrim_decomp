// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unked79d0: STANDIN GUESS(low)
// Unked79d0::Functioned79d0: GUESS(low)
// Unked79d0::value, GlobalStateed79d0, gStateed79d0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct GlobalStateed79d0 { std::uint8_t unknown00[32]; void* value; };
extern GlobalStateed79d0* gStateed79d0;
class Unked79d0
{
public:
    void Functioned79d0();
    void* value;
};
static_assert(offsetof(Unked79d0, value) == 0, "field offset");
