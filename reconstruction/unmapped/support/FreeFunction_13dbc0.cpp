// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x13dbc0 Function13dbc0
// Adapted bodies: none
#include "FreeFunction_13dbc0.h"

// Destroys each polymorphic 0xE8-byte element in [first, last).
void Function13dbc0(Item13dbc0* first, Item13dbc0* last)
{
    for (; first != last; ++first)
    {
        first->~Item13dbc0();
    }
}
