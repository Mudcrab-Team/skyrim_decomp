// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: HandleRefPtr17bdc0::operator=, treated as adapted: shaped like NiPointer::reset (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:140, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x17bdc0 HandleRefPtr17bdc0::operator=
// CI hash: 0x17bdc0 ??4HandleRefPtr17bdc0@@QEAAAEAV0@PEAUHandleRefObject17bdc0@@@Z
#include "HandleRefPtr17bdc0.h"

// Assigns rhs to the smart pointer, updating atomic handle-object reference counts.
HandleRefPtr17bdc0& HandleRefPtr17bdc0::operator=(HandleRefObject17bdc0* rhs)
{
    HandleRefObject17bdc0* old = ptr;
    if (old != rhs) {
        if (rhs != nullptr) {
            rhs->IncRefCount();
        }
        ptr = rhs;
        if (old != nullptr) {
            old->DecRefCount();
        }
    }
    return *this;
}
