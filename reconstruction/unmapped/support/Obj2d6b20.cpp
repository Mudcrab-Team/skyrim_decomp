// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// 0x2d6b20 Obj2d6b20::Format
// Adapted bodies: none
#include "Obj2d6b20.h"

#include <cstdarg>
#include <cstdio>

// Guess: format a varargs string into the output buffer via vsprintf.
void Obj2d6b20::Format(char* a_buffer, const char* a_format, ...)
{
    std::va_list args;
    va_start(args, a_format);
    std::vsprintf(a_buffer, a_format, args);
    va_end(args);
}
