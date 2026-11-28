// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: RefPtr21eda0::operator=, treated as adapted: shaped like NiPointer::operator= and NiRefObject::IncRefCount and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:78, src/RE/N/NiRefObject.cpp:22, src/RE/N/NiRefObject.cpp:28, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x21eda0 RefPtr21eda0::operator=
// CI hash: 0x21eda0 ??4RefPtr21eda0@@QEAAAEAV0@AEBV0@@Z
#include "RefPtr21eda0.h"

// Assign a reference-counted object pointer, updating reference counts atomically.
RefPtr21eda0& RefPtr21eda0::operator=(const RefPtr21eda0& rhs)
{
    RefObject21eda0* newObj = rhs.object;
    RefObject21eda0* oldObj = object;
    if (newObj != oldObj)
    {
        if (newObj)
        {
            // Atomic reference count increment for shared object ownership.
            _InterlockedIncrement(&newObj->refCount);
        }
        object = newObj;
        if (oldObj)
        {
            // Atomic reference count decrement for shared object ownership.
            if (_InterlockedExchangeAdd(&oldObj->refCount, -1) == 1)
            {
                delete oldObj;
            }
        }
    }
    return *this;
}
