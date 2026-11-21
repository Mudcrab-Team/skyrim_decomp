// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// 0xe7c2b0 BSPCOrbisGamepadDevice::Release
// Adapted bodies: none
#include "BSPCOrbisGamepadDevice_e7c2b0.h"

void BSPCOrbisGamepadDevice::Release()
{
    if (userIndex > 0) {
        scePadClose(userIndex);
    }
}
