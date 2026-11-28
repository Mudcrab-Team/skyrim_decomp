// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0xbf9680 BlockTableBf9680::SetEntry
// Adapted bodies: none.
#include "BlockTableBf9680.h"

void BlockTableBf9680::SetEntry(int a_index, const Block32Bf9680& a_value)
{
    entries[a_index] = a_value;
}
