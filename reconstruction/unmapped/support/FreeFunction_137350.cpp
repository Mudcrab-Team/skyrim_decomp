// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x137350 Function137350
// Adapted bodies: none
#include "FreeFunction_137350.h"

// Clears an array's element count and optionally releases its heap storage.
void Function137350(Array137350* arr, bool release)
{
    if (arr->data != nullptr)
    {
        if (release)
        {
            arr->ReleaseData();
        }
        arr->size = 0;
    }
}
