// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x2cb160 Obj2cb160::Function2cb160
// Adapted bodies: none
#include "Obj2cb160.h"

// Returns the interior loaded-data field address or the exterior worldspace pointer.
void* Obj2cb160::Function2cb160() const
{
    if ((cellFlags & 0x1u) != 0) {
        return &loadedData->fieldB0;
    }
    return worldSpace->field138;
}
