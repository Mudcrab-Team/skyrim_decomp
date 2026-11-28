// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0xd0a640 Functiond0a640
// Adapted bodies: none
#include <cstdarg>
#include "FreeFunction_d0a640.h"

// Forwards a variadic log message through the primary logger base vtable.
void Functiond0a640(LoggerBase2d0a640* a_self, const char* a_fmt, ...)
{
    std::va_list args;
    va_start(args, a_fmt);
    static_cast<LoggerDerivedd0a640*>(a_self)->LogMessageVarg(0x20, a_fmt, args);
    va_end(args);
}
