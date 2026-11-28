// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Unit201ce0::Clear201ce0 and IntrusivePtr201ce0::~IntrusivePtr201ce0, treated as adapted: shaped like NiPointer::~NiPointer and NiRefObject::DecRefCount and BSTArray::release (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/N/NiRefObject.cpp:28, include/RE/B/BSTArray.h:641, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x201ce0 Unit201ce0::Clear201ce0
#include "Unit201ce0.h"

// Deletes every non-null entry in the array and optionally deallocates the backing buffer.
void Unit201ce0::Clear201ce0(bool a_deallocate)
{
    if (count != 0) {
        Entry201ce0** it = data;
        Entry201ce0** end = data + count;
        for (; it != end; ++it) {
            delete *it;
        }
    }

    if (data) {
        if (a_deallocate) {
            Deallocate();
        }
        count = 0;
    }
}
