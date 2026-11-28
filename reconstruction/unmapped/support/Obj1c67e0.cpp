// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj1c67e0::~Obj1c67e0, treated as adapted: shaped like BSTSmartPointerIntrusiveRefCount::Release (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/B/BSTSmartPointer.h:13, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1c67e0 Obj1c67e0::~Obj1c67e0
#include "Obj1c67e0.h"

#include <intrin.h>

// Releases the held reference-counted target, deleting it when the reference count hits zero.
Obj1c67e0::~Obj1c67e0()
{
    RefTarget1c67e0* target = ptr;
    if (target) {
        // atomic intrusive reference count decrement
        if (_InterlockedDecrement(&target->refCount30) == 0) {
            delete target;
        }
    }
}
