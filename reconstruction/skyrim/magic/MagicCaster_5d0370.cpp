// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x5d0370 MagicCaster::ResetEntries
// Adapted bodies: none
#include "MagicCaster_5d0370.h"

void MagicCaster::ResetEntries(uint32_t a_first, uint32_t a_count)
{
    MagicCasterEntry* entry = &entries[a_first];
    for (uint32_t i = 0; i < a_count; ++i, ++entry) {
        entry->id = -1;
        entry->flag = 0;
        entry->value = 0;
    }
}
