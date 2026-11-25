// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x5da340 ActiveEffect::Function5da340
// Adapted bodies: none
#include "ActiveEffect_5da340.h"

bool ActiveEffect::Function5da340(ActiveEffect* a_other)
{
    if (a_other) {
        void* otherKey = a_other->Function5bb090()->sub_1400FB930();
        if (otherKey && otherKey == Function5bb090()->sub_1400FB930()) {
            return true;
        }
    }

    return false;
}
