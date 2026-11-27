// Source exposure: mixed.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// MapCamera: STANDIN COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// MapCamera::Function558d80: GUESS(low)
// MapCamera::positionX, MapCamera::positionY, MapCamera::positionZ: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>



class MapCamera
{
public:
    void Function558d80(float x, float y, float z);
    std::uint8_t unknown0[16];
    float positionX;
    float positionY;
    float positionZ;
};
static_assert(offsetof(MapCamera, positionX) == 16, "field offset");
static_assert(offsetof(MapCamera, positionY) == 20, "field offset");
static_assert(offsetof(MapCamera, positionZ) == 24, "field offset");
