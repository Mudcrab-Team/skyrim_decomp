// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x1265d0 Function1265d0
// Adapted bodies: none
#include "FreeFunction_1265d0.h"

// Formats a va_list string into a character buffer via vsprintf.
int Function1265d0(char* a_buf, const char* a_fmt, std::va_list a_args)
{
    return std::vsprintf(a_buf, a_fmt, a_args);
}
