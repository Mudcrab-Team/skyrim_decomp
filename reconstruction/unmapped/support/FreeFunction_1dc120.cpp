// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1dc120 CopyEntryTable1dc120
// Adapted bodies: none
#include "FreeFunction_1dc120.h"

// Copies each non-null pair of entries across a 38-slot table.
void CopyEntryTable1dc120(SlotEntry1dc120** a_dest, SlotEntry1dc120** a_source)
{
    if (!a_source) {
        return;
    }

    for (std::size_t i = 0; i < kEntryCount; ++i) {
        if (a_dest[i] && a_source[i]) {
            a_dest[i]->CopyFrom(a_source[i]);
        }
    }
}
