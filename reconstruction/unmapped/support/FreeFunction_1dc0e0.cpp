// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1dc0e0 ClearEntryTable1dc0e0
// Adapted bodies: none
#include "FreeFunction_1dc0e0.h"

// Calls Clear on each non-null entry across a 38-slot entry table.
void ClearEntryTable1dc0e0(SlotEntry1dc0e0** a_entries)
{
    for (std::uint32_t i = 0; i < kEntryCount; ++i) {
        if (a_entries[i]) {
            a_entries[i]->Clear();
        }
    }
}
