// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x125280 StringAllocator125280::Destroy
// Adapted bodies: none
#include "StringAllocator125280.h"

// Destroys a std::string instance in place.
// guess: a stateless allocator member; the call does not read this.
void StringAllocator125280::Destroy(std::string* a_str)
{
    using Str = std::string;
    a_str->~Str();
}
