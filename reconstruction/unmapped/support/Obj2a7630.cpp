// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x2a7630 Obj2a7630::Function2a7630
// Adapted bodies: none
#include "Obj2a7630.h"

// Returns true when active, startTime exceeds threshold, and elapsed time exceeds duration.
bool Obj2a7630::Function2a7630(float a_startTime) const
{
    if (!active || a_startTime <= 0.0001f) {
        return false;
    }
    return (g_currentTime2a7630 - a_startTime) > duration;
}
