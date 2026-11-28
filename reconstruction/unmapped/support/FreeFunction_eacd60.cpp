// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0xeacd60 Functioneacd60
// Adapted bodies: none
#include "FreeFunction_eacd60.h"

// Frees a non-null 16-byte-aligned block through the global allocator.
void Functioneacd60(void* ptr)
{
    if (ptr != nullptr) {
        g_allocatorHolder_eacd60->allocator->Free(ptr, 16u, static_cast<std::size_t>(-1));
    }
}
