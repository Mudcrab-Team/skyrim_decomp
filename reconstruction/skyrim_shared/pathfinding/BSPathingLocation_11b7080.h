// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSPathingLocation: STANDIN GUESS(low)
// BSPathingLocation::Function11b7080: GUESS(low)
// BSPathingLocation::object, BSPathingLocation::index, PathObject11b7080: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct PathObject11b7080 { std::uint8_t unknown00[40]; void* value; };

class BSPathingLocation
{
public:
    bool Function11b7080();
    std::uint8_t unknown0[16];
    PathObject11b7080* object;
    std::uint8_t unknown18[16];
    std::uint16_t index;
};
static_assert(offsetof(BSPathingLocation, object) == 16, "field offset");
static_assert(offsetof(BSPathingLocation, index) == 40, "field offset");
