// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x10bcb0 DuplicateNarrowString10bcb0
// Adapted bodies: none
#include "FreeFunction_10bcb0.h"

#include <cstddef>
#include <cstring>

extern "C" {
__declspec(dllimport) void* __cdecl calloc(std::size_t a_count, std::size_t a_size);
__declspec(dllimport) __declspec(noreturn) void __cdecl abort();
}

char* DuplicateNarrowString10bcb0(const char* a_source)
{
    const std::size_t count = std::strlen(a_source) + 1;
    char* const copy = static_cast<char*>(calloc(count, 1));
    if (copy == nullptr) {
        abort();
    }
    char* dst = copy;
    for (std::size_t n = count; n != 0; --n) {
        *dst++ = *a_source++;
    }
    return copy;
}
