// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x2cb190 Obj2cb190::Function2cb190
// Adapted bodies: none
#include "Obj2cb190.h"

// Returns the interior loaded-data field address or the exterior worldspace pointer.
void* Obj2cb190::Function2cb190() const
{
    if ((cellFlags & 0x1u) != 0) {
        return &loadedData->fieldD0;
    }
    return worldSpace->field140;
}
