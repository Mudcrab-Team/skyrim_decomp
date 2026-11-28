// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1cbc90 Obj1cbc90::GetEntry
// Adapted bodies: none.
#include "Obj1cbc90.h"

// Returns this for index 0, or the (a_index - 1)-th entry from entries468 when in range.
Obj1cbc90* Obj1cbc90::GetEntry(std::uint32_t a_index)
{
    if (a_index <= count460) {
        if (a_index == 0) {
            return this;
        }
        if (entries468) {
            return entries468[a_index - 1];
        }
    }
    return 0;
}
