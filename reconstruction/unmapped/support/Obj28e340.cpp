// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj28e340::~Obj28e340 and RefCounted28e340::DecRef, treated as adapted: shaped like NiPointer::~NiPointer and BSHandleRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/B/BSHandleRefObject.cpp:12, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x28e340 Obj28e340::~Obj28e340
#include "Obj28e340.h"

// Releases the held reference-counted target pointer.
Obj28e340::~Obj28e340()
{
    if (ptr) {
        ptr->DecRef();
    }
}
