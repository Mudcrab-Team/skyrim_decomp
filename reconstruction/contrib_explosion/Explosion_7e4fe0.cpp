// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x7e4fe0 Explosion::Function7e4fe0
// Adapted bodies: none
#include "Explosion_7e4fe0.h"

void Explosion::Function7e4fe0()
{
    if (!unk60 && Get3D2()) {
        ObjectParams params;
        params.value = gDefaultObjectValue;
        params.flag = 1;
        Get3D2()->Function0ee0930(&params);
    }
}
