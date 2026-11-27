// Source exposure: mixed.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// PathFollowerStateFollowPathToParameter: STANDIN COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// PathFollowerStateFollowPathToParameter::Function1245e50: GUESS(low)
// PathFollowerStateFollowPathToParameter::x, PathFollowerStateFollowPathToParameter::y, PathFollowerStateFollowPathToParameter::z, PathFollowerStateFollowPathToParameter::storedData: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>



class PathFollowerStateFollowPathToParameter
{
public:
    void Function1245e50(void* context, float first, float second, float third, void* data);
    std::uint8_t unknown0[8];
    float x;
    float y;
    float z;
    std::uint8_t unknown14[4];
    void* storedData;
};
static_assert(offsetof(PathFollowerStateFollowPathToParameter, x) == 8, "field offset");
static_assert(offsetof(PathFollowerStateFollowPathToParameter, y) == 12, "field offset");
static_assert(offsetof(PathFollowerStateFollowPathToParameter, z) == 16, "field offset");
static_assert(offsetof(PathFollowerStateFollowPathToParameter, storedData) == 24, "field offset");
