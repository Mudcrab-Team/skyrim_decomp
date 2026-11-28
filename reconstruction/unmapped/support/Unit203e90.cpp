// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x203e90 Unit203e90::Unit203e90
// Adapted bodies: none
#include "Unit203e90.h"

// Initializes the six color words to 0xFFFFFF, tail to zero, and scale to 1.0f.
Unit203e90::Unit203e90()
{
    values[0] = 0xFFFFFFu;
    values[1] = 0xFFFFFFu;
    values[2] = 0xFFFFFFu;
    values[3] = 0xFFFFFFu;
    values[4] = 0xFFFFFFu;
    values[5] = 0xFFFFFFu;
    tail = 0;
    scale = 1.0f;
}
