// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x4adbc0 BSTempEffectGeometryDecal::Release
// Adapted bodies: none
#include "BSTempEffectGeometryDecal_4adbc0.h"

#include <intrin.h>

void BSTempEffectGeometryDecal::Release()
{
    RefObject* object = ref;
    if (object) {
        // atomic refcount: the reference may be shared between threads
        if (_InterlockedDecrement(reinterpret_cast<volatile long*>(&object->refCount)) == 0) {
            delete object;
        }
    }
}
