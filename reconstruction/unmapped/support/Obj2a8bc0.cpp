// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2a8bc0::Function2a8bc0, RefObject2a8bc0::IncRef and DecRef, treated as adapted: shaped like NiPointer::operator= and NiRefObject::IncRefCount and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:78, src/RE/N/NiRefObject.cpp:22, src/RE/N/NiRefObject.cpp:28, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2a8bc0 Obj2a8bc0::Function2a8bc0
#include "Obj2a8bc0.h"

// Assigns a raw reference-counted pointer, updating reference counts.
Obj2a8bc0& Obj2a8bc0::Function2a8bc0(RefObject2a8bc0* a_rhs)
{
    RefObject2a8bc0* old = ptr;
    if (old != a_rhs) {
        if (a_rhs) {
            a_rhs->IncRef();
        }
        ptr = a_rhs;
        if (old) {
            old->DecRef();
        }
    }
    return *this;
}
