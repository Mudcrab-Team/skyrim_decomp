// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x5e2440 ShaderReferenceEffect::Function5e2440
// Adapted bodies: none
#include "ShaderReferenceEffect_5e2440.h"

void ShaderReferenceEffect::Function5e2440(bool a_enable)
{
    if (a_enable) {
        unk130 |= 2;
    } else {
        unk130 &= ~2u;
    }
}
