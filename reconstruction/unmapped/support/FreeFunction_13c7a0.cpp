// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x13c7a0 Function13c7a0
// Adapted bodies: none
#include "FreeFunction_13c7a0.h"

// Destroys each polymorphic 0xE8-byte element in [first, last).
void Function13c7a0(Item13c7a0* first, Item13c7a0* last)
{
    for (; first != last; ++first)
    {
        first->~Item13c7a0();
    }
}
