// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x10c890 Vector10c890::Clear
// Adapted bodies: none
#include "Vector10c890.h"

// Destroys all elements in the vector range and resets the end pointer to the start.
void Vector10c890::Clear()
{
    DestroyRange10c890(first, last, this);
    last = first;
}
