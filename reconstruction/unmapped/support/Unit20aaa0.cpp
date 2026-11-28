// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Unit20aaa0::~Unit20aaa0 and IntrusivePtr20aaa0::~IntrusivePtr20aaa0, treated as adapted: shaped like NiPointer::~NiPointer and NiRefObject::DecRefCount and BSTArray::~BSTArray (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/N/NiRefObject.cpp:28, include/RE/B/BSTArray.h:427, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x20aaa0 Unit20aaa0::~Unit20aaa0
#include "Unit20aaa0.h"

// Destroys each intrusive pointer element, deallocates the buffer, and resets the count.
Unit20aaa0::~Unit20aaa0()
{
    IntrusivePtr20aaa0* ptr = data;
    if (ptr) {
        const std::uint32_t n = count;
        for (std::uint32_t i = 0; i < n; ++i) {
            ptr[i].~IntrusivePtr20aaa0();
        }
        Deallocate();
        count = 0;
    }
}
