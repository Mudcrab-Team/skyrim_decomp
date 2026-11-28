// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x153940 Function153940
// Adapted bodies: none
#include "FreeFunction_153940.h"

// Maps codes 0x12..0x16 to indices 0..4, returning 5 otherwise.
std::int32_t Function153940(std::int32_t value)
{
    std::int32_t result = 5;
    switch (value)
    {
    case 0x12:
        result = 0;
        break;
    case 0x13:
        result = 1;
        break;
    case 0x14:
        result = 2;
        break;
    case 0x15:
        result = 3;
        break;
    case 0x16:
        result = 4;
        break;
    }
    return result;
}
