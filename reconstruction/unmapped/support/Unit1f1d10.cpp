// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1f1d10 Unit1f1d10::RemoveEntry1f1d10
// Adapted bodies: none
#include "Unit1f1d10.h"

// Removes a matching entry from the array, shifting or swap-removing according to a_preserveOrder.
void Unit1f1d10::RemoveEntry1f1d10(const void* a_entry, bool a_preserveOrder)
{
    if (!array) {
        return;
    }

    for (std::uint32_t i = 0; i < array->count; ++i) {
        if (array->data[i] == a_entry) {
            if (a_preserveOrder) {
                for (std::uint32_t j = i; j < array->count - 1; ++j) {
                    array->data[j] = array->data[j + 1];
                }
            } else {
                array->data[i] = array->data[array->count - 1];
            }
            i = array->count;
            --array->count;
        }
    }
}
