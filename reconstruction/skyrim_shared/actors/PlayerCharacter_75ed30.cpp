// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x75ed30 PlayerCharacter::Function75ed30
// Adapted bodies: none
#include "PlayerCharacter_75ed30.h"

void PlayerCharacter::Function75ed30(float* out)
{
    const float* src = reinterpret_cast<const float*>(reinterpret_cast<const char*>(this) - 0x78);
    out[0] = src[0];
    out[1] = src[1];
    out[2] = src[2];
    out[0] = 0.0f;
}
