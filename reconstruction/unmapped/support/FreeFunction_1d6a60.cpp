// Source exposure: binary-analysis (pinned image listing; CrashLogger PDB name hint).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1d6a60 FloatCeil
// Adapted bodies: none
#include "FreeFunction_1d6a60.h"

// Ceiling by way of a signed 32-bit integer conversion.
// NOTE: original behaviour: the result is the ceiling only for inputs that fit that integer; NaN and larger
// magnitudes are out of range for the conversion and give another value.
float FloatCeil(float a_value)
{
    float truncated = static_cast<float>(static_cast<std::int32_t>(a_value));
    if (!(truncated - a_value >= 0.0f)) {
        truncated += 1.0f;
    }
    return truncated;
}
