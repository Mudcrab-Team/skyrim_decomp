// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj19b940::Assign, RefTarget19b940::IncRef and DecRef, treated as adapted: shaped like NiPointer::operator= and NiRefObject::IncRefCount and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:78, src/RE/N/NiRefObject.cpp:22, src/RE/N/NiRefObject.cpp:28, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x19b940 Obj19b940::Assign
#include "Obj19b940.h"

// Replaces the managed reference-counted pointer with a_rhs and returns this smart pointer.
Obj19b940& Obj19b940::Assign(RefTarget19b940* a_rhs)
{
    RefTarget19b940* old = ptr;
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
