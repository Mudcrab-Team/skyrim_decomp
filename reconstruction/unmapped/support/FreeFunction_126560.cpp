// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x126560 Function126560
// Adapted bodies: none
#include "FreeFunction_126560.h"

// Formats a counted va_list string with an explicit locale via UCRT vsnprintf_l.
int Function126560(char* a_buf, std::size_t a_count, const char* a_fmt, _locale_t a_locale, std::va_list a_args)
{
    return _vsnprintf_l(a_buf, a_count, a_fmt, a_locale, a_args);
}
