// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0x4adbf0 (skyrim_shared/tempeffects/BSTempEffectGeometryDecal_4adbf0): source copied, names replaced by placeholders.
// SPDX-License-Identifier: CC0-1.0
// 0x2b60c0 Owner2b60c0::Function2b60c0
#include "Owner2b60c0.h"
#include <intrin.h>

// guess: same compiled code as matched 0x4adbf0 apart from relocated fields; its role here is not established.
Owner2b60c0* Owner2b60c0::Function2b60c0(RefObject* a_other)
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
