// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1caf60 Obj1caf60::HasActiveTarget
// Adapted bodies: none.
#include "Obj1caf60.h"

// Checks whether the primary or secondary target pointer is non-null based on mode flags.
bool Obj1caf60::HasActiveTarget() const
{
    if (g_flag1caf60 && flag29) {
        if (ptr18) {
            return true;
        }
    } else if (ptr38) {
        return true;
    }
    return false;
}
