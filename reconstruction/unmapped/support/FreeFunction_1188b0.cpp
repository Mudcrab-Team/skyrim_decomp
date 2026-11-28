// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1188b0 FormatStringLocale1188b0
// Adapted bodies: none.
#include "FreeFunction_1188b0.h"

#include <cstdint>

extern "C" {
std::uint64_t* __cdecl __local_stdio_printf_options();
__declspec(dllimport) int __cdecl __stdio_common_vsprintf_s(
    std::uint64_t a_options,
    char* a_buffer,
    std::size_t a_bufferCount,
    const char* a_format,
    void* a_locale,
    std::va_list a_argList);
}

// The community name table calls this _vsprintf_s_l (a hint, not proof); this unit declares its own wrapper under a stand-in name.
int FormatStringLocale1188b0(
    char* a_buffer,
    std::size_t a_bufferCount,
    const char* a_format,
    void* a_locale,
    std::va_list a_argList)
{
    const int result = __stdio_common_vsprintf_s(
        *__local_stdio_printf_options(),
        a_buffer,
        a_bufferCount,
        a_format,
        a_locale,
        a_argList);
    return result < 0 ? -1 : result;
}
