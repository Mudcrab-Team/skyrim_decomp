// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x4f8730 PathingRequestLOS::~PathingRequestLOS
// Adapted bodies: none
#include "PathingRequestLOS_4f8730.h"
#include <intrin.h>

PathingRequestLOS::~PathingRequestLOS()
{
    RefTarget* p = target;
    if (p && _InterlockedDecrement(&p->refCount) == 0) {  // intrinsic: atomic refcount release
        delete p;
    }
}
