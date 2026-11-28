// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing using standard library headers
// SPDX-License-Identifier: CC0-1.0
// 0x10c1d0 Function10c1d0
// Adapted bodies: none
#include "FreeFunction_10c1d0.h"

#include <string.h>

// Moves count bytes between potentially overlapping buffers with bounds checking.
int Function10c1d0(void* destination, std::size_t destinationSize, const void* source, std::size_t count)
{
    return memmove_s(destination, destinationSize, source, count);
}
