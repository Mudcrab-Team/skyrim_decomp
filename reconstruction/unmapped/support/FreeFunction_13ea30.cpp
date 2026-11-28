// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x13ea30 Function13ea30
// Adapted bodies: none
#include "FreeFunction_13ea30.h"

// Destroys each polymorphic 0xE8-byte element in the range [first, last).
void Function13ea30(Range13ea30* range)
{
    Item13ea30* last = range->last;
    for (Item13ea30* cur = range->first; cur != last; ++cur)
    {
        cur->~Item13ea30();
    }
}
