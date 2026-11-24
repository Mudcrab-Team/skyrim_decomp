// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x9ad110 BGSLoadGameBuffer::Function9ad110
// Adapted bodies: none
#include "BGSLoadGameBuffer_9ad110.h"

// Reads the extra byte only from save versions that have it.
void BGSLoadGameBuffer::Function9ad110()
{
    if (GetVersion() >= 0x1f) {
        LoadDataEndian(&gLoadedByte, 1, 1);
    }
}
