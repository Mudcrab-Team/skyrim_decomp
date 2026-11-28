// Source exposure: mixed (community-generated layout and the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing; array count (3312 / 24 = 138) from TESDataHandler_1c3680.h.
// SPDX-License-Identifier: CC0-1.0
// 0x1ba840 Obj1ba840::GetAt
// Adapted bodies: none.
#include "Obj1ba840.h"

// Returns the element at a_index in the selected form array, or null if out of range.
void* Obj1ba840::GetAt(std::uint8_t a_slot, std::uint32_t a_index) const
{
    const Array1ba840& arr = formArrays10[a_slot];
    if (a_index < arr.size) {
        return arr.data[a_index];
    }
    return 0;
}
