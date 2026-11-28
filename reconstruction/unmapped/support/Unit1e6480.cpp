// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1e6480 Unit1e6480::SetFlagBit11
// Adapted bodies: none
#include "Unit1e6480.h"

// Updates bit 11 of the flags word and notifies MarkChanged(1) if the value changed.
void Unit1e6480::SetFlagBit11(bool a_set)
{
    if (static_cast<bool>((flags >> 11) & 1u) != a_set) {
        if (a_set) {
            flags |= 0x800u;
        } else {
            flags &= ~0x800u;
        }
        MarkChanged(1u);
    }
}
