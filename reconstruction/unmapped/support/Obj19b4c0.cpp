// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: PtrA19b4c0 and PtrB19b4c0 destructors and the DecRef helpers, treated as adapted: shaped like NiPointer::~NiPointer and BSTSmartPointerIntrusiveRefCount::Release and BSHandleRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, include/RE/B/BSTSmartPointer.h:13, src/RE/B/BSHandleRefObject.cpp:12, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x19b4c0 Obj19b4c0::~Obj19b4c0
#include "Obj19b4c0.h"

// Destroys the object, releasing both intrusive smart-pointer members in reverse order.
Obj19b4c0::~Obj19b4c0()
{
}
