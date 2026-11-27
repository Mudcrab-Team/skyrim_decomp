// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x7ae030 PlayerControls::IsCamSwitchControlsEnabled
// Adapted bodies: none
#include "PlayerControls_7ae030.h"

// Return whether camera-switch controls are enabled in the control map and neither disable flag is set.
bool PlayerControls::IsCamSwitchControlsEnabled() const
{
    bool enabled = ((g_controlMap7ae030->unk120 >> 5) & 1) != 0;
    for (std::uint16_t i = 0; i < 2 && enabled; ++i) {
        if (unk4C[i]) {
            enabled = false;
        }
    }
    return enabled;
}
