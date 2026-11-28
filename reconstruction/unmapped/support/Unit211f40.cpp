// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x211f40 Unit211f40::ShiftRange211f40
// Adapted bodies: none
#include "Unit211f40.h"

#include <cstring>

// Shifts the pointer range [a_start, a_end) up by one slot in both parallel arrays.
void Unit211f40::ShiftRange211f40(std::uint32_t a_start, std::uint32_t a_end)
{
    const std::uint32_t count = a_end - a_start;
    if (count == 0) {
        return;
    }

    const std::uint32_t bytes = count * 8u;
    memmove_s(&first[a_start] + 1, bytes, &first[a_start], bytes);
    memmove_s(&second[a_start] + 1, bytes, &second[a_start], bytes);
}
