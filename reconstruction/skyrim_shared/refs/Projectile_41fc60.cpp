// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x41fc60 Projectile::GetDeathForce
// Adapted bodies: none
#include "Projectile_41fc60.h"

#include <cmath>

// Remap the magnitude of an input float across one of two configured input/output ranges with clamping.
float Projectile::GetDeathForce(float value, bool useAlternate)
{
    float inMin;
    float inMax;
    float outMin;
    float outMax;
    if (useAlternate) {
        inMin = gAltInMin;
        inMax = gAltInMax;
        outMin = gAltOutMin;
        outMax = gAltOutMax;
    } else {
        inMin = gInMin;
        inMax = gInMax;
        outMin = gOutMin;
        outMax = gOutMax;
    }

    float t = (std::fabs(value) - inMin) / (inMax - inMin);
    if (t < 0.0f) {
        t = 0.0f;
    }
    if (t > 1.0f) {
        t = 1.0f;
    }
    return t * (outMax - outMin) + outMin;
}
