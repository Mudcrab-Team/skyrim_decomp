// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x1374d0 Function1374d0
// Adapted bodies: none
#include "FreeFunction_1374d0.h"

// Forwards an 8-byte element shift operation to the array's size subobject.
void Function1374d0(Array1374d0* arr, std::uint32_t dstIndex, std::uint32_t srcIndex, std::uint32_t count)
{
    arr->sizePart.Shift(arr->data, dstIndex, srcIndex, count, 8);
}
