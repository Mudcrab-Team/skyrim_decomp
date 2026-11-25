// Source exposure: binary-analysis (pinned-image observations).
// Code origin: original; observed accesses with guessed type and field names
// SPDX-License-Identifier: CC0-1.0
// UI_image, Function15f5880, UI_imagePoint, UI_imageHitResult: GUESS(low); owner and descriptive names remain uncorroborated.
// UI_image, UI_imagePoint, UI_imageHitResult: STANDIN GUESS(low); partial layouts preserve accessed fields.
// left, top, right, bottom, hitValue: GUESS(low); inferred from point comparisons and result copying.
#pragma once

#include <cstddef>
#include <cstdint>

class UI_image;

struct UI_imagePoint
{
    float x;
    float y;
};

struct UI_imageHitResult
{
    UI_image* image;  // 0x00
    std::uint8_t unknown08[0x0c];
    std::uint32_t hitValue;  // 0x14
};

class UI_image
{
public:
    bool Function15f5880(const UI_imagePoint& point, UI_imageHitResult* result);

    std::uint8_t unknown00[0x0c];
    float left;  // 0x0c
    float top;  // 0x10
    float right;  // 0x14
    float bottom;  // 0x18
    std::uint8_t unknown1c[0x34];
    std::uint32_t hitValue;  // 0x50
};
static_assert(offsetof(UI_image, left) == 0x0c, "left bound offset");
static_assert(offsetof(UI_image, top) == 0x10, "top bound offset");
static_assert(offsetof(UI_image, right) == 0x14, "right bound offset");
static_assert(offsetof(UI_image, bottom) == 0x18, "bottom bound offset");
static_assert(offsetof(UI_image, hitValue) == 0x50, "hit value offset");
static_assert(offsetof(UI_imageHitResult, hitValue) == 0x14, "result hit value offset");
