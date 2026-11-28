// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing using standard library headers
// SPDX-License-Identifier: CC0-1.0
// 0x10c240 Function10c240
// Adapted bodies: none
#include "FreeFunction_10c240.h"

#include <string.h>

// Copies count bytes into destination with bounds checking and discards the status code.
void Function10c240(void* destination, std::size_t destinationSize, const void* source, std::size_t count)
{
    memcpy_s(destination, destinationSize, source, count);
}
