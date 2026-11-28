// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x10b920 DuplicateWideString10b920
// Adapted bodies: none.
#include "FreeFunction_10b920.h"

#include <cstddef>
#include <cstring>

extern "C" {
std::size_t __cdecl wcslen(const wchar_t* a_str);
__declspec(dllimport) void* __cdecl calloc(std::size_t a_count, std::size_t a_size);
__declspec(dllimport) __declspec(noreturn) void __cdecl abort();
}

wchar_t* DuplicateWideString10b920(const wchar_t* a_source)
{
    const std::size_t count = wcslen(a_source) + 1;
    wchar_t* const copy = static_cast<wchar_t*>(calloc(count, sizeof(wchar_t)));
    if (copy == nullptr) {
        abort();
    }
    std::memcpy(copy, a_source, count * sizeof(wchar_t));
    return copy;
}
