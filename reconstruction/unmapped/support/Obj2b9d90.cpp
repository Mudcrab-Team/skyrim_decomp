// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Entry2b9d90::~Entry2b9d90, RefCounted2b9d90::DecRef and Obj2b9d90::Function2b9d90, treated as adapted: shaped like NiPointer::~NiPointer and BSHandleRefObject::DecRefCount and BSTArray::release (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/B/BSHandleRefObject.cpp:12, include/RE/B/BSTArray.h:641, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2b9d90 Obj2b9d90::Function2b9d90
#include "Obj2b9d90.h"

// Destroys every entry in the global array and resets its count to zero.
void Obj2b9d90::Function2b9d90()
{
    Entry2b9d90* data = g_array2b9d90.data;
    if (data) {
        std::uint32_t count = g_array2b9d90.size;
        for (std::uint32_t i = 0; i < count; ++i) {
            data[i].~Entry2b9d90();
        }
        g_array2b9d90.size = 0;
    }
}
