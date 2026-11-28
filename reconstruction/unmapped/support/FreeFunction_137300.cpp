// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x137300 Function137300
// Adapted bodies: none
#include "FreeFunction_137300.h"

// Removes the element at index by shifting subsequent 8-byte entries or clearing a single element.
void Function137300(Array137300* arr, std::uint32_t index)
{
    std::uint32_t count = arr->sizePart.size;
    void* data = arr->data;
    if (count == 1)
    {
        if (data != nullptr)
        {
            arr->sizePart.size = 0;
        }
        return;
    }
    arr->sizePart.Shift(data, index, index + 1, count - index - 1, 8);
    --arr->sizePart.size;
}
