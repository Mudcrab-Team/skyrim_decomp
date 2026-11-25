// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x75d3c0 PlayerCharacter::Function75d3c0
// Adapted bodies: none
#include "PlayerCharacter_75d3c0.h"

bool PlayerCharacter::Function75d3c0()
{
    if (!unkE3()) {
        float threshold = gThreshold;
        if (GetValue679b50() > threshold) {
            return true;
        }
    }
    return false;
}
