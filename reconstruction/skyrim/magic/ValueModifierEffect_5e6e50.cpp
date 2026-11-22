// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x5e6e50 ValueModifierEffect::ClearTargetImpl
// Adapted bodies: none
#include "ValueModifierEffect_5e6e50.h"

void ValueModifierEffect::ClearTargetImpl()
{
    if (ShouldModifyOnFinish() && TestBit(flags, 16) && !TestBit(flags, 17)) {
        Finish();
        flags |= 0x20000;
    }
    ActiveEffect::ClearTargetImpl();
}
