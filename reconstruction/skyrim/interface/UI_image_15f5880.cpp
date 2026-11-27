// Source exposure: binary-analysis (pinned-image observations).
// Code origin: original; handwritten bounds query and result update
// SPDX-License-Identifier: CC0-1.0
// 0x15f5880 UI_image::Function15f5880
// Adapted bodies: none
#include "UI_image_15f5880.h"

// Tests the point against the bounds and records the selected image.
bool UI_image::Function15f5880(const UI_imagePoint& point, UI_imageHitResult* result)
{
    if (point.x > right || !(point.x >= left) || point.y > bottom || !(point.y >= top))
    {
        return false;
    }
    result->image = this;
    result->hitValue = hitValue;
    return true;
}
