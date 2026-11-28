// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1b3060 Obj1b3060::~Obj1b3060
// Adapted bodies: none.
#include "Obj1b3060.h"

// Releases the held owner lock according to mode and resets the guard state.
Obj1b3060::~Obj1b3060()
{
    if (owner00) {
        Lock1b3060* lock = owner00->lock430;
        if (mode08 == 0) {
            if (lock) {
                lock->UnlockA();
            }
        } else {
            if (lock) {
                lock->UnlockB();
            }
        }
        owner00 = 0;
        mode08 = 2;
    }
}
