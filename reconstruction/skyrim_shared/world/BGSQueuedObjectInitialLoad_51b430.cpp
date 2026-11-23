// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x51b430 BGSQueuedObjectInitialLoad::Function51b430
// Adapted bodies: none
#include "BGSQueuedObjectInitialLoad_51b430.h"

bool BGSQueuedObjectInitialLoad::Function51b430() const
{
    if (target) {
        const std::uint32_t bits = target->state & 0x70000000;
        return bits == 0x30000000 || bits == 0x40000000;
    }
    return false;
}
