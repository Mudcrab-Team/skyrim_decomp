// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// 0x31c530 Obj31c530::Print
// Adapted bodies: none
#include "Obj31c530.h"

#include <cstdarg>
#include <cstdio>

// Guess: write a formatted varargs message to stdout via vprintf.
void Obj31c530::Print(const char* a_format, ...)
{
    std::va_list args;
    va_start(args, a_format);
    std::vprintf(a_format, args);
    va_end(args);
}
