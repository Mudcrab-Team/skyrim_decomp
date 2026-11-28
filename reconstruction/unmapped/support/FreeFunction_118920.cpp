// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x118920 FormatString118920
// Adapted bodies: none.
#include "FreeFunction_118920.h"

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

int FormatString118920(
    char* a_buffer,
    std::size_t a_bufferCount,
    const char* a_format,
    std::va_list a_argList)
{
    const int result = __stdio_common_vsprintf_s(
        *__local_stdio_printf_options(),
        a_buffer,
        a_bufferCount,
        a_format,
        nullptr,
        a_argList);
    return result < 0 ? -1 : result;
}
