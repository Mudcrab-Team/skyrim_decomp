// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x13a06d0 FixedBuffer13a06d0::Format
// Adapted bodies: none
#include <cstdarg>
#include "FixedBuffer13a06d0.h"

// Formats a variadic string into a 512-byte inline buffer, clamping length at 511 on truncation.
FixedBuffer13a06d0& FixedBuffer13a06d0::Format(const char* a_fmt, ...)
{
    std::va_list args;
    va_start(args, a_fmt);
    FormatV(a_fmt, args);
    va_end(args);
    return *this;
}
