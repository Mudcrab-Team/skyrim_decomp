// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2c45b0::Function2c45b0, treated as adapted: shaped like TESObjectCELL::GetDistanceFromPoint in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesobjectcell.cpp:14642
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x2c45b0 Obj2c45b0::Function2c45b0
#include "Obj2c45b0.h"

#include <cmath>

// Computes 2D distance from a_pos to the exterior cell's 4096x4096 world-space bounds.
// NOTE: beyond maxX with y inside the bounds, the compared code returns minX - x, as written below.
float Obj2c45b0::Function2c45b0(const Point2D2c45b0& a_pos) const
{
    float minX;
    float minY;
    if ((cellFlags & 0x1u) == 0 && cellData) {
        minX = cellData->minX;
        minY = cellData->minY;
    } else {
        minX = 0.0f;
        minY = 0.0f;
    }
    float maxX = minX + 4096.0f;
    float maxY = minY + 4096.0f;
    float x = a_pos.x;
    float y = a_pos.y;

    if (x < minX) {
        if (y > maxY) {
            float dx = x - minX;
            float dy = y - maxY;
            return std::sqrt(dx * dx + dy * dy);
        }
        if (y < minY) {
            float dx = x - minX;
            float dy = y - minY;
            return std::sqrt(dx * dx + dy * dy);
        }
        return minX - x;
    }
    if (x > maxX) {
        if (y > maxY) {
            float dx = x - maxX;
            float dy = y - maxY;
            return std::sqrt(dx * dx + dy * dy);
        }
        if (y < minY) {
            float dx = x - maxX;
            float dy = y - minY;
            return std::sqrt(dx * dx + dy * dy);
        }
        return minX - x;
    }
    if (y > maxY) {
        return y - maxY;
    }
    if (y < minY) {
        return minY - y;
    }
    return 0.0f;
}
