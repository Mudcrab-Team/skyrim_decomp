// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x2b2960 Obj2b2960::Function2b2960
// Adapted bodies: none
#include "Obj2b2960.h"

// Computes the world-space center coordinates of the land tile.
Point3D2b2960 Obj2b2960::Function2b2960() const
{
    Point3D2b2960 result;
    std::int32_t gridX;
    if (data40) {
        gridX = data40->coordX;
    } else if (cell30) {
        gridX = cell30->GetCoordX();
    } else {
        gridX = 0;
    }
    result.x = static_cast<float>(gridX << 12) + 2048.0f;

    std::int32_t gridY;
    if (data40) {
        gridY = data40->coordY;
    } else if (cell30) {
        gridY = cell30->GetCoordY();
    } else {
        gridY = 0;
    }
    result.y = static_cast<float>(gridY << 12) + 2048.0f;

    result.z = data40 ? data40->baseHeight : 0.0f;
    return result;
}
