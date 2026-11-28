// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x153900 Function153900
// Adapted bodies: none
#include "FreeFunction_153900.h"

// Maps indices 0..4 to codes 0x12..0x16, returning -1 otherwise.
std::int32_t Function153900(std::int32_t value)
{
    std::int32_t result = -1;
    switch (value)
    {
    case 0:
        result = 0x12;
        break;
    case 1:
        result = 0x13;
        break;
    case 2:
        result = 0x14;
        break;
    case 3:
        result = 0x15;
        break;
    case 4:
        result = 0x16;
        break;
    }
    return result;
}
