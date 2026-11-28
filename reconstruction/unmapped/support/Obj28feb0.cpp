// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x28feb0 Obj28feb0::Obj28feb0
// Adapted bodies: none
#include "Obj28feb0.h"

// Initializes five default-named sub-slots and field90 to zero.
Obj28feb0::Obj28feb0()
{
    slot00.Init(g_defaultStrA28feb0);
    slot30.Init(g_defaultStrB28feb0);
    slot60.Init(g_defaultStrA28feb0);
    field90 = 0;
    slot98.Init(g_defaultStrC28feb0);
    slotC8.Init(g_defaultStrD28feb0);
}
