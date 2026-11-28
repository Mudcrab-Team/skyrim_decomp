// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0xe40870 Functione40870
// Adapted bodies: none
#include "FreeFunction_e40870.h"

// Returns buffer->size, excluding a trailing NUL code unit when present.
std::size_t Functione40870(const WideBuffer_e40870* buffer)
{
    std::size_t length = buffer->size;
    if (length != 0) {
        const std::uint16_t* last = buffer->At(length - 1);
        if (*last == 0) {
            --length;
        }
    }
    return length;
}
