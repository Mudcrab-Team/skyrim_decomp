// Source exposure: mixed.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// MapCamera: STANDIN COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// MapCamera::Function558db0: GUESS(low)
// MapCamera::storedValue: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>



class MapCamera
{
public:
    void Function558db0(float value);
    std::uint8_t unknown0[28];
    float storedValue;
};
static_assert(offsetof(MapCamera, storedValue) == 28, "field offset");
