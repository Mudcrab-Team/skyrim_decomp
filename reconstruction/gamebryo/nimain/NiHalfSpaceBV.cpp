// Source exposure: mixed (local binary analysis and public names).
// Code origin: original reconstruction written for this project from the pinned image listing; no community or sibling body adapted.
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0xf3a000 NiHalfSpaceBV::Functionf3a000
// 0xf3bd50 NiHalfSpaceBV::Slot3
// Adapted bodies: none
#include "NiHalfSpaceBV.h"

// Tests whether the other volume is a half-space with the same plane coefficients.
bool NiHalfSpaceBV::Functionf3a000(const NiHalfSpaceBV& other) const
{
    if (other.Slot3() != 5) {
        return false;
    }
    return other.coefficients[0] == coefficients[0]
        && other.coefficients[1] == coefficients[1]
        && other.coefficients[2] == coefficients[2]
        && other.coefficients[3] == coefficients[3];
}

// Returns the half-space type code that the comparison above tests against 5.
std::uint32_t NiHalfSpaceBV::Slot3() const
{
    return 0x5;
}
