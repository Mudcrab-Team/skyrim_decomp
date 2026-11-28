// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0xfde8b0 Functionfde8b0
// Adapted bodies: none
#include "FreeFunction_fde8b0.h"

// Converts an IEEE 754 binary16 half-precision value to single-precision float.
// The community name table calls this HalfToFloat (a hint, not proof); its integer return type differs from the float returned here.
float Functionfde8b0(std::uint16_t half)
{
    std::uint32_t bits = half;
    std::uint32_t mantissa = bits & 0x3FFu;
    std::uint32_t expField = bits & 0x7C00u;
    std::int32_t exponent;

    if (expField == 0x7C00u) {
        exponent = 0x8F;
    } else if (expField != 0) {
        exponent = (bits >> 10) & 0x1Fu;
    } else if (mantissa != 0) {
        exponent = 1;
        do {
            --exponent;
            mantissa <<= 1;
        } while ((mantissa & 0x400u) == 0);
        mantissa &= 0x3FFu;
    } else {
        exponent = -112;
    }

    union
    {
        std::uint32_t u;
        float f;
    } result;
    std::uint32_t biased = exponent + 112;
    result.u = ((bits & 0x8000u) << 16) | (biased << 23) | (mantissa << 13);
    return result.f;
}
