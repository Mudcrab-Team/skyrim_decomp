// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: SmartPtr17be10::operator=, RefCountBase17be10::IncRef and DecRef, treated as adapted: shaped like NiPointer::operator= and BSHandleRefObject::DecRefCount and BSHandleRefObject::IncRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:78, src/RE/B/BSHandleRefObject.cpp:12, src/RE/B/BSHandleRefObject.cpp:20, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x17be10 SmartPtr17be10::operator=
// CI hash: 0x17be10 ??4SmartPtr17be10@@QEAAAEAU0@PEAURefObject17be10@@@Z
#include "SmartPtr17be10.h"

// Rebinds the smart pointer, incrementing the new target and releasing the previous one.
SmartPtr17be10& SmartPtr17be10::operator=(RefObject17be10* rhs)
{
    RefObject17be10* old = ptr;
    if (old != rhs)
    {
        if (rhs != nullptr)
        {
            rhs->IncRef();
        }
        ptr = rhs;
        if (old != nullptr)
        {
            old->DecRef();
        }
    }
    return *this;
}
