// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x18a980 ExtraAttachedArrows3D::Function18a980
// Adapted bodies: none
#include "ExtraAttachedArrows3D_18a980.h"

void ExtraAttachedArrows3D::Function18a980()
{
    if (holder) {
        ArrowTarget* target = holder->Get28();
        if (target) {
            target->flags0F4 &= ~0x8000u;
            target->flags109 |= 1;
        }
    }
}
