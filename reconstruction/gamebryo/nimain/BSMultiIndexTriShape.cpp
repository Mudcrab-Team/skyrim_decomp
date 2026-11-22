// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original body from the pinned image listing; declarations are stand-in guesses.
// SPDX-License-Identifier: CC0-1.0
// 0x15754b0 BSMultiIndexTriShape::Function15754b0
// Adapted bodies: none for Function15754b0.
// Code origin: original reconstruction from binary analysis by Taylor Turner, assisted by claude-sonnet-5-5; class and member names come from CommonLibSSE-NG (MIT), and no external implementation body or layout is copied.
// Source exposure: binary-analysis. Drafted by Taylor Turner, assisted by claude-sonnet-5-5.
#include "BSMultiIndexTriShape.h"

// Body from the pinned image listing; names are stand-ins.
// 0x15754b0 BSMultiIndexTriShape::Function15754b0
// Adapted bodies: none
void BSMultiIndexTriShape::Function15754b0(void* a_value)
{
    if (target) {
        target->value = a_value;
    }
}

BSMultiIndexTriShape* BSMultiIndexTriShape::AsMultiIndexTriShape()
{
    return this;
}
