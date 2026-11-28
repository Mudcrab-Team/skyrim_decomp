// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
// 0xef2e80 NiColor::Clamp
#include "NiColor_ef2e80.h"

// Clamp each RGB color channel to at most 1.0.
void NiColor::Clamp()
{
    if (1.0f < r) {
        r = 1.0f;
    }
    if (1.0f < g) {
        g = 1.0f;
    }
    if (1.0f < b) {
        b = 1.0f;
    }
}
