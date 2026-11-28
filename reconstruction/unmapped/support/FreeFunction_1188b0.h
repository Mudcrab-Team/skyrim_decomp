// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1188b0
// Adapted bodies: none.
// FormatStringLocale1188b0: GUESS(low) STANDIN
#pragma once

#include <cstdarg>
#include <cstddef>

int FormatStringLocale1188b0(
    char* a_buffer,
    std::size_t a_bufferCount,
    const char* a_format,
    void* a_locale,
    std::va_list a_argList);
