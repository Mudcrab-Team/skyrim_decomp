// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x24b0d0 Obj24b0d0::Obj24b0d0
// Adapted bodies: none
#include "Obj24b0d0.h"

// Initialize fields and copy the default global position.
Obj24b0d0::Obj24b0d0()
{
    flag = 0;
    ptr = nullptr;
    position.x = g_defaultPosition.x;
    position.y = g_defaultPosition.y;
    position.z = g_defaultPosition.z;
}
