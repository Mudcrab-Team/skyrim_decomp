// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x7afcb0 PlayerControls::sub_140706880
// Adapted bodies: none
#include "PlayerControls_7afcb0.h"

// Clear input handler state and reset control flags.
void PlayerControls::sub_140706880()
{
    unk180->ClearState(0);
    unk1B8->ClearState(0);
    unk1C0->ClearState(0);
    unk4C = 0;
    unk1A0->unk1B = false;
}
