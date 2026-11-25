// Source exposure: binary-analysis (pinned-image observations).
// Code origin: original.
// SPDX-License-Identifier: CC0-1.0
// 0x1609e00 UI_image2::Function1609e00
// Adapted bodies: none.
// Recipe: reconstruction/recipes/o2-fpfast.json
// Cookbook: 48
#include "UI_image2_1609e00.h"

bool UI_image2::Function1609e00(const ImagePoint* point, ImageHit* hit)
{
    if (point->x > right || point->x < left || point->y > bottom || point->y < top)
        return false;
    hit->image = this;
    hit->index = hitIndex;
    return true;
}
