// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x11d760 Function11d760
// Adapted bodies: none
#include "FreeFunction_11d760.h"

// Releases the static array buffer if allocated and resets its count.
void Function11d760()
{
    if (gStaticArray11d760.data != nullptr)
    {
        gStaticArray11d760.Deallocate();
        gStaticArray11d760.size = 0;
    }
}
