// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB name.
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
// 0x4220e0 ActiveEffect::GetTaperedMagnitude
#include "ActiveEffect_4220e0.h"

#include <cfloat>
#include <cmath>

// Computes the tapered magnitude of an effect over elapsed time and duration.
float ActiveEffect::GetTaperedMagnitude(
    float a_magnitude,
    float a_elapsed,
    float a_duration,
    float a_taperWeight,
    float a_taperCurve)
{
    if (a_elapsed < 0.0f)
    {
        a_elapsed = 0.0f;
    }
    if (a_elapsed < a_duration)
    {
        if (std::fabs(a_elapsed) <= 0.0001f && a_taperCurve < 0.0f)
        {
            return a_magnitude > 0.0f ? FLT_MAX : -FLT_MAX;
        }
        a_magnitude *= std::pow(a_elapsed / a_duration, a_taperCurve) * a_taperWeight;
    }
    return a_magnitude;
}
