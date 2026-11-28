// Source exposure: mixed (community-generated layout and the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing; array count (3312 / 24 = 138) from TESDataHandler_1c3680.h.
// SPDX-License-Identifier: CC0-1.0
// 0x1ba870 Obj1ba870::FindIndex
// Adapted bodies: none.
#include "Obj1ba870.h"

// Searches the selected form array for a_item and returns its index, or -1 if absent.
std::int32_t Obj1ba870::FindIndex(std::uint8_t a_slot, void* a_item) const
{
    const Array1ba870& arr = formArrays10[a_slot];
    std::uint32_t i = 0;
    std::int32_t result = -1;
    while (i < arr.size && result == -1) {
        if (arr.data[i] == a_item) {
            result = static_cast<std::int32_t>(i);
        }
        ++i;
    }
    return result;
}
