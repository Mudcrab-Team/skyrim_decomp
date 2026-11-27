// Source exposure: mixed.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// PathFollowerStateKeepLastDirection: STANDIN COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// PathFollowerStateKeepLastDirection::Function1246b70: GUESS(low)
// PathFollowerStateKeepLastDirection::x, PathFollowerStateKeepLastDirection::y, PathFollowerStateKeepLastDirection::z, PathFollowerStateKeepLastDirection::value, PathFollowerStateKeepLastDirection::storedData, Direction1246b70: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Direction1246b70 { float x; float y; float z; };

class PathFollowerStateKeepLastDirection
{
public:
    void Function1246b70(void* context, const Direction1246b70& direction, float parameter, void* data);
    std::uint8_t unknown0[8];
    float x;
    float y;
    float z;
    float value;
    void* storedData;
};
static_assert(offsetof(PathFollowerStateKeepLastDirection, x) == 8, "field offset");
static_assert(offsetof(PathFollowerStateKeepLastDirection, y) == 12, "field offset");
static_assert(offsetof(PathFollowerStateKeepLastDirection, z) == 16, "field offset");
static_assert(offsetof(PathFollowerStateKeepLastDirection, value) == 20, "field offset");
static_assert(offsetof(PathFollowerStateKeepLastDirection, storedData) == 24, "field offset");
