// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x1047ea0 Function1047ea0
// Adapted bodies: none
#include "FreeFunction_1047ea0.h"

// Searches a nullable container's entry array linearly for a matching 32-bit key.
bool Function1047ea0(const Container1047ea0* a_container, std::uint32_t a_key)
{
    if (!a_container) {
        return false;
    }
    for (std::int32_t i = 0; i < a_container->count; ++i) {
        if (a_container->entries[i].key == a_key) {
            return true;
        }
    }
    return false;
}
