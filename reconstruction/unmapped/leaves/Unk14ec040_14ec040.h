// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk14ec040: STANDIN GUESS(low)
// Unk14ec040::Function14ec040: GUESS(low)
// LookupObject14ec040, gObjects14ec040: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct LookupObject14ec040 { std::uint8_t unknown00[544]; void* value; };
extern LookupObject14ec040* gObjects14ec040[];
class Unk14ec040
{
public:
    static void* Function14ec040(std::int32_t index);
};
