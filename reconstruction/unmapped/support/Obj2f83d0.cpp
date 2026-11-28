// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// 0x2f83d0 Obj2f83d0::~Obj2f83d0
// Adapted bodies: none
#include "Obj2f83d0.h"

// Guess: unregister form factory 0x3D and destroy base subobject.
Obj2f83d0::~Obj2f83d0()
{
    UnregisterFactory2f83d0(0x3D);
}
