// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x5dc6e0 ActiveEffectReferenceEffectController::GetScale
// Adapted bodies: none; the one-line TestBit helper in the header follows docs/matching-cookbook.md rule 16 and resembles a
// momusdigital/f3_decomp@f5bac1b f3blk_004e0000_o2.cpp:49422 helper only by shape (CC0-1.0)
#include "ActiveEffectReferenceEffectController_5dc6e0.h"

float ActiveEffectReferenceEffectController::GetScale()
{
    if (TestBit(effect->flags, 12)) {
        if (!effect->GetBaseObject()->Function14b7e0()) {
            return effect->GetBaseObject()->dualCastScale;
        }
    }
    return 1.0f;
}
