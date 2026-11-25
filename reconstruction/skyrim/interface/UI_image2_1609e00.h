// Source exposure: binary-analysis (pinned-image observations).
// Code origin: original.
// SPDX-License-Identifier: CC0-1.0
// UI_image2, UI_image2::Function1609e00, ImagePoint, ImageHit: GUESS(low) STANDIN
// left, top, right, bottom, hitIndex, image, index, x, y, unknown00, unknown1c, unknown08: GUESS(low)
#pragma once
#include <cstdint>
#include <cstddef>

class UI_image2;
struct ImagePoint { float x; float y; };
struct ImageHit {
    UI_image2* image;
    std::uint8_t unknown08[12];
    std::uint32_t index;
};
class UI_image2
{
public:
    bool Function1609e00(const ImagePoint* point, ImageHit* hit);
    std::uint8_t unknown00[0x0c];
    float left;
    float top;
    float right;
    float bottom;
    std::uint8_t unknown1c[0x34];
    std::uint32_t hitIndex;
};
static_assert(offsetof(UI_image2, hitIndex) == 0x50, "hit index offset");
static_assert(offsetof(ImageHit, index) == 0x14, "hit result index offset");
