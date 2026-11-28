// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x299c40 Obj299c40::Function299c40
// Adapted bodies: none
#include "Obj299c40.h"

// Updates cleared and everCleared flags and marks change flag 0x80000000 when cleared.
void Obj299c40::Function299c40(bool a_cleared)
{
    cleared = a_cleared;
    everCleared = everCleared || a_cleared;
    if (a_cleared) {
        AddChange(0x80000000u);
    }
}
