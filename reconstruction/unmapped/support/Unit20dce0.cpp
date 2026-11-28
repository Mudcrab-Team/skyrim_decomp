// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x20dce0 Unit20dce0::Reset20dce0
// Adapted bodies: none
#include "Unit20dce0.h"

// Clears six independent global variables.
// guess: whether they belong to one object is unknown; a single struct global gives a different size.
void Unit20dce0::Reset20dce0()
{
    g_active20dce0 = false;
    g_firstPointer20dce0 = nullptr;
    g_secondPointer20dce0 = nullptr;
    g_firstValue20dce0 = 0;
    g_thirdPointer20dce0 = nullptr;
    g_secondValue20dce0 = 0;
}
