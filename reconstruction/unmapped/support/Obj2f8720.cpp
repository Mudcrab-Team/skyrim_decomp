// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2f8720::operator= and RefObj2f8720::Release, treated as adapted: shaped like NiPointer::operator= and NiRefObject::IncRefCount and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:78, src/RE/N/NiRefObject.cpp:22, src/RE/N/NiRefObject.cpp:28, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2f8720 Obj2f8720::operator=
// CI hash: 0x2f8720 ??4Obj2f8720@@QEAAAEAV0@PEAVRefObj2f8720@@@Z
#include "Obj2f8720.h"

// Guess: replace the managed intrusive pointer, updating reference counts.
Obj2f8720& Obj2f8720::operator=(RefObj2f8720* a_rhs)
{
    RefObj2f8720* old = m_ptr;
    if (old != a_rhs)
    {
        if (a_rhs)
        {
            // Atomic refcount increment on assignment.
            _InterlockedIncrement(&a_rhs->m_refCount);
        }
        m_ptr = a_rhs;
        if (old)
        {
            old->Release();
        }
    }
    return *this;
}
