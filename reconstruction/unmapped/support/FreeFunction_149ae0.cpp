// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x149ae0 Function149ae0
// Adapted bodies: none
#include "FreeFunction_149ae0.h"

#include <cstring>

// Returns the cached 16-bit string length, or computes strlen when the sentinel 0xFFFF is stored.
std::size_t Function149ae0(const StringData149ae0* str)
{
    if (str->length == 0xFFFF)
    {
        return std::strlen(str->data);
    }
    return str->length;
}
