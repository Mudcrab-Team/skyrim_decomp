// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xeeb4f0 BSDynamicTriShape::Functioneeb4f0
// Adapted bodies: none
#include "BSDynamicTriShape_eeb4f0.h"

void BSDynamicTriShape::Functioneeb4f0()
{
    RefCounted* held = object;
    if (held) {
        object = nullptr;
        // atomic release of a shared reference; the last holder deletes the object
        if (_InterlockedDecrement(&held->refCount) == 0) {
            held->DeleteThis();
        }
    }
}
