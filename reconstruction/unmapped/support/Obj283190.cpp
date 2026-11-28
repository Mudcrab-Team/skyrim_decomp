// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x283190 Obj283190::Function283190
// Adapted bodies: none
#include "Obj283190.h"

// Sets or clears flag bit 0x08 in flagsB0.
void Obj283190::Function283190(bool a_enable)
{
    if (a_enable) {
        flagsB0 |= 0x8u;
    } else {
        flagsB0 &= ~0x8u;
    }
}
