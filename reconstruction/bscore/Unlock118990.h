// Source exposure: binary-analysis
// Unlock118990: GUESS(low) STANDIN; original owner is unknown
// Function118990: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
#include <cstdarg>
#include <cstdio>

class Unlock118990 {
public:
    static int Function118990(char* dest, std::size_t size, const char* format, ...);
};

inline int FormatUnflagged(char* dest, std::size_t size, const char* format, va_list args)
{
    int result = __stdio_common_vsprintf(*__local_stdio_printf_options(), dest, size, format, nullptr, args);
    return result < 0 ? -1 : result;
}
