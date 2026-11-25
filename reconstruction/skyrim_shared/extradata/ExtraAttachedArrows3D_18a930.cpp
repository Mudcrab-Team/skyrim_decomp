// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x18a930 ExtraAttachedArrows3D::Function18a930
// Adapted bodies: none
#include "ExtraAttachedArrows3D_18a930.h"

bool ExtraAttachedArrows3D::Function18a930()
{
    if (holder) {
        ArrowTarget* target = holder->Get28();
        if (target) {
            if (target->flags109 & 1) {
                return true;
            }
            float value = target->value130;
            if (value > 0.0f && !(value >= 1.0f)) {
                return true;
            }
        }
    }
    return false;
}
