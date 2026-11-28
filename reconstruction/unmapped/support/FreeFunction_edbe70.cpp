// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0xedbe70 Functionedbe70
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
#include "FreeFunction_edbe70.h"

#include <cmath>

// Computes the angle in radians from the positive Y axis for a 2D vector (x, y).
// The community name table calls this NiPoint3AngleFromXAxis (a hint, not proof); the comment above states what the code computes, and the names are stand-ins.
float Functionedbe70(const Vec2_edbe70* vec)
{
    float x = vec->x;
    float y = vec->y;
    if (y != 0.0f) {
        float angle = std::atanf(x / y);
        if (y < 0.0f) {
            angle += 3.1415927f;
        }
        return angle;
    }
    if (x > 0.0f) {
        return 1.5707964f;
    }
    return -1.5707964f;
}
