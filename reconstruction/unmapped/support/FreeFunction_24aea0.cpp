// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0x24aea0 Function24aea0
// Adapted bodies: none
#include "FreeFunction_24aea0.h"

// Finds target in array->data and returns its index, or 0xFFFFFFFF if absent.
std::uint32_t Function24aea0(const Array24aea0* array, const void* target)
{
    if (target == nullptr) {
        return 0xFFFFFFFFu;
    }

    std::uint32_t count = array->size;
    if (count == 0) {
        return 0xFFFFFFFFu;
    }

    for (std::uint32_t i = 0; i < count; ++i) {
        if (array->data[i] == target) {
            return i;
        }
    }
    return 0xFFFFFFFFu;
}
