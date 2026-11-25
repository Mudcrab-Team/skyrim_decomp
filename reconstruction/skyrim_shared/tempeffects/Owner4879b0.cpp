// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0x4adbc0 (skyrim_shared/tempeffects/BSTempEffectGeometryDecal_4adbc0): source copied, names replaced by placeholders.
// SPDX-License-Identifier: CC0-1.0
// 0x4879b0 Owner4879b0::Function4879b0
#include "Owner4879b0.h"
#include <intrin.h>

// guess: same compiled code as matched 0x4adbc0 apart from relocated fields; its role here is not established.
void Owner4879b0::Function4879b0()
{
    RefObject* object = ref;
    if (object) {
        // atomic refcount: the reference may be shared between threads
        if (_InterlockedDecrement(reinterpret_cast<volatile long*>(&object->refCount)) == 0) {
            delete object;
        }
    }
}
