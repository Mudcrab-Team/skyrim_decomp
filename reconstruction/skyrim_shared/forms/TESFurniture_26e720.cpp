// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x26e720 TESFurniture::sub_1402198E0
#include "TESFurniture_26e720.h"

// Return whether the given furniture marker index is in range and enabled in the bitmask.
bool TESFurniture::sub_1402198E0(std::uint32_t a_index) const
{
    bool enabled = false;
    if (a_index < 25) {
        if ((enabledMarkers & (1u << a_index)) != 0) {
            enabled = true;
        }
    }
    return enabled;
}
