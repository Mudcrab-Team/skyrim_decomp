// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing using standard library headers
// SPDX-License-Identifier: CC0-1.0
// 0x13c6e0 Function13c6e0
// Adapted bodies: none
#include "FreeFunction_13c6e0.h"

// Destroys each element in [first, last).
void Function13c6e0(Element13c6e0* first, Element13c6e0* last)
{
    for (; first != last; ++first) {
        first->~Element13c6e0();
    }
}
