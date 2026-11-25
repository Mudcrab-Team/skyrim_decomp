// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x4adbf0 BSTempEffectGeometryDecal::Assign
// Adapted bodies: none
#include "BSTempEffectGeometryDecal_4adbf0.h"

#include <intrin.h>

BSTempEffectGeometryDecal* BSTempEffectGeometryDecal::Assign(RefObject* a_other)
{
    RefObject* old = ref;
    if (old != a_other) {
        if (a_other) {
            // atomic refcount: the reference may be shared between threads
            _InterlockedIncrement(reinterpret_cast<volatile long*>(&a_other->refCount));
        }
        ref = a_other;
        if (old) {
            // atomic refcount: the reference may be shared between threads
            if (_InterlockedDecrement(reinterpret_cast<volatile long*>(&old->refCount)) == 0) {
                delete old;
            }
        }
    }
    return this;
}
