// Source exposure: mixed (pinned community declarations and private target analysis).
// Code origin: original handwritten reconstruction.
// SPDX-License-Identifier: CC0-1.0
// 0x28c410 TESObjectWEAP::Function28c410
// Adapted bodies: none
#include "TESObjectWEAP_28c410.h"

// Reads the setting for a supported weapon type, with a unit fallback.
float TESObjectWEAP::Function28c410() const
{
    const std::int8_t type = weaponData.animationType;
    if (static_cast<std::uint8_t>(type) <= 9) {
        return g_weaponTypeSettings[type]->data.f;
    }
    return 1.0f;
}
