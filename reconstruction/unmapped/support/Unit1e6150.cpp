// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1e6150 Unit1e6150::SetFlagBit6
// Adapted bodies: none
#include "Unit1e6150.h"

// Updates bit 6 of the flags word and notifies MarkChanged(1) if the value changed.
void Unit1e6150::SetFlagBit6(bool a_set)
{
    if (static_cast<bool>((flags >> 6) & 1u) != a_set) {
        if (a_set) {
            flags |= 0x40u;
        } else {
            flags &= ~0x40u;
        }
        MarkChanged(1u);
    }
}
