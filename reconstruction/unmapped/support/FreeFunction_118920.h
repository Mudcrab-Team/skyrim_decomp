// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x118920
// Adapted bodies: none.
// FormatString118920: GUESS(low) STANDIN
#pragma once

#include <cstdarg>
#include <cstddef>

int FormatString118920(
    char* a_buffer,
    std::size_t a_bufferCount,
    const char* a_format,
    std::va_list a_argList);
