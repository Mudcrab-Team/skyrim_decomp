// Source exposure: mixed.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// ImageSpaceShaderParam: STANDIN COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// ImageSpaceShaderParam::Function152b1e0: GUESS(low)
// ImageSpaceShaderParam::value, gFlag152b1e0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>


extern std::uint8_t gFlag152b1e0;
class ImageSpaceShaderParam
{
public:
    void Function152b1e0();
    std::uint8_t unknown0[12];
    bool value;
};
static_assert(offsetof(ImageSpaceShaderParam, value) == 12, "field offset");
