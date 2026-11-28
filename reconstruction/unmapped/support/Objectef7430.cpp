// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0xef7430 Objectef7430::Objectef7430
// CI hash: 0xef7430 ??0Objectef7430@@QEAA@XZ
// Adapted bodies: none
#include "Objectef7430.h"

// Default-initializes position, then copies coordinates from g_defaultPos_ef7430 and clears unk0C.
Objectef7430::Objectef7430()
{
    position.x = g_defaultPos_ef7430.x;
    position.y = g_defaultPos_ef7430.y;
    position.z = g_defaultPos_ef7430.z;
    unk0C = 0;
}
