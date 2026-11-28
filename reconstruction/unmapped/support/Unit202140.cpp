// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Unit202140::~Unit202140 and IntrusivePtr202140::~IntrusivePtr202140, treated as adapted: shaped like NiPointer::~NiPointer and NiRefObject::DecRefCount and BSTArray::~BSTArray (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/N/NiRefObject.cpp:28, include/RE/B/BSTArray.h:427, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x202140 Unit202140::~Unit202140
#include "Unit202140.h"

// Destroys each intrusive pointer element, deallocates the buffer, and resets the count.
Unit202140::~Unit202140()
{
    IntrusivePtr202140* ptr = data;
    if (ptr) {
        const std::uint32_t n = count;
        for (std::uint32_t i = 0; i < n; ++i) {
            ptr[i].~IntrusivePtr202140();
        }
        Deallocate();
        count = 0;
    }
}
