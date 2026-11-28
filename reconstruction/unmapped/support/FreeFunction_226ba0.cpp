// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x226ba0 FormatString226ba0
// Adapted bodies: none
#include "FreeFunction_226ba0.h"

#include <cstdarg>
#include <cstdio>

// Format a variadic string into the destination buffer using vsprintf.
int FormatString226ba0(char* buffer, const char* format, ...)
{
    va_list args;
    va_start(args, format);
    int written = std::vsprintf(buffer, format, args);
    va_end(args);
    return written;
}
