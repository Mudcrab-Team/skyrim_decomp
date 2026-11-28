// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x20d3d0 Unit20d3d0::EqualsCString20d3d0
// Adapted bodies: none
#include "Unit20d3d0.h"

#include <cstring>

// Compares the prefix-stripped string against a_other, returning false when a_other is null.
// NOTE: original behaviour: only the prefix test checks for null; a null text still reaches strcmp.
bool Unit20d3d0::EqualsCString20d3d0(const char* a_other) const
{
    if (a_other) {
        return std::strcmp(GetStripped(), a_other) == 0;
    }

    return false;
}
