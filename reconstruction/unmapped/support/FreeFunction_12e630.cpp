// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x12e630 Function12e630
// Adapted bodies: none
#include "FreeFunction_12e630.h"

// Fills a character range with a repeated byte value and returns the destination pointer.
char* Function12e630(char* a_dst, std::size_t a_count, char a_ch)
{
    std::memset(a_dst, a_ch, a_count);
    return a_dst;
}
