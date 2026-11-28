// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x2a46c0 Obj2a46c0::Function2a46c0
// Adapted bodies: none
#include "Obj2a46c0.h"

#include <cmath>

// Returns true when the magnitude of duration exceeds 0.0001 and elapsed time exceeds duration.
bool Obj2a46c0::Function2a46c0() const
{
    if (std::fabsf(duration) > 0.0001f) {
        return (g_currentTime2a46c0 - startTime) > duration;
    }
    return false;
}
