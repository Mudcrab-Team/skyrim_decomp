// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: SmartPtr2f7e70::~SmartPtr2f7e70, RefObj2f7e70::Release and Obj2f7e70::~Obj2f7e70, treated as adapted: shaped like NiPointer::~NiPointer and NiRefObject::DecRefCount and BSTArray::~BSTArray (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/N/NiRefObject.cpp:28, include/RE/B/BSTArray.h:427, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2f7e70 Obj2f7e70::~Obj2f7e70
#include "Obj2f7e70.h"

// Guess: destroy each smart-pointer element, deallocate storage, and reset array size.
Obj2f7e70::~Obj2f7e70()
{
    SmartPtr2f7e70* data = m_data;
    if (data)
    {
        const std::uint32_t count = m_size;
        for (std::uint32_t i = 0; i < count; ++i)
        {
            data[i].~SmartPtr2f7e70();
        }
        Deallocate();
        m_size = 0;
    }
}
