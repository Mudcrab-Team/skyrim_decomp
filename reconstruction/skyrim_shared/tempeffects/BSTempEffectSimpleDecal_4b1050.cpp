// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x4b1050 BSTempEffectSimpleDecal::ReleaseGlobalPreloadParent
// Adapted bodies: none
#include "BSTempEffectSimpleDecal_4b1050.h"
#include <intrin.h>

void BSTempEffectSimpleDecal::ReleaseGlobalPreloadParent()
{
    PreloadParent* parent = preloadParent;
    if (parent) {
        preloadParent = nullptr;
        // reference counts are shared across threads, so the decrement is atomic
        if (_InterlockedDecrement(&parent->refCount) == 0) {
            delete parent;
        }
    }
}
