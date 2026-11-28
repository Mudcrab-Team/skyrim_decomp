// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Unit205c50::~Unit205c50 and IntrusivePtr205c50::~IntrusivePtr205c50, treated as adapted: shaped like NiPointer::~NiPointer and BSTSmartPointerIntrusiveRefCount::Release and BSTArray::~BSTArray (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, include/RE/B/BSTSmartPointer.h:13, include/RE/B/BSTArray.h:427, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x205c50 Unit205c50::~Unit205c50
#include "Unit205c50.h"

// Destroys each intrusive pointer element, deallocates the buffer, and resets the count.
Unit205c50::~Unit205c50()
{
    IntrusivePtr205c50* ptr = data;
    if (ptr) {
        const std::uint32_t n = count;
        for (std::uint32_t i = 0; i < n; ++i) {
            ptr[i].~IntrusivePtr205c50();
        }
        Deallocate();
        count = 0;
    }
}
