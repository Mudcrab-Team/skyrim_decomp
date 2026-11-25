// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0x4adbc0 (skyrim_shared/tempeffects/BSTempEffectGeometryDecal_4adbc0): source copied, names replaced by placeholders.
// SPDX-License-Identifier: CC0-1.0
// 0x8a6680 Owner8a6680::Function8a6680
#include "Owner8a6680.h"
#include <intrin.h>

// guess: same compiled code as matched 0x4adbc0 apart from relocated fields; its role here is not established.
void Owner8a6680::Function8a6680()
{
    RefObject* object = ref;
    if (object) {
        // atomic refcount: the reference may be shared between threads
        if (_InterlockedDecrement(reinterpret_cast<volatile long*>(&object->refCount)) == 0) {
            delete object;
        }
    }
}
