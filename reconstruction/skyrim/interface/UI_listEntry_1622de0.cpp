// Source exposure: binary-analysis.
// Code origin: original; pinned-image observations and labelled naming sources.
// SPDX-License-Identifier: CC0-1.0
// 0x1622de0 UI_listEntry::Function1622de0
// Adapted bodies: none.
#include "UI_listEntry_1622de0.h"

bool UI_listEntry::Function1622de0(const QueryPoint& point, QueryResult& result)
{
    const float x = point.x;
    const float y = point.y;
    if (x > right || !(x >= left)) {
        return false;
    }
    if (y > bottom || !(y >= top) || !(x > minimumCoordinate)) {
        return false;
    }
    result.selected = this;
    result.value = value;
    return true;
}
