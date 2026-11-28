// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: SmartPtr3156b0::~SmartPtr3156b0, RefBase3156b0::Release and Obj3156b0::RemoveRange, treated as adapted: shaped like NiPointer::~NiPointer and BSHandleRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/B/BSHandleRefObject.cpp:12, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x3156b0 Obj3156b0::RemoveRange
#include "Obj3156b0.h"

// Guess: destroy a slice of smart-pointer array entries and fill the gap from the tail.
void Obj3156b0::RemoveRange(std::uint32_t a_index, std::uint32_t a_count)
{
    const std::uint32_t tail = m_size - a_index - a_count;
    const std::uint32_t moveCount = (tail < a_count) ? tail : a_count;

    SmartPtr3156b0* elem = m_data + a_index;
    for (std::uint32_t i = 0; i < a_count; ++i)
    {
        elem[i].~SmartPtr3156b0();
    }

    MoveElements(m_data, a_index, m_size - moveCount, moveCount, sizeof(SmartPtr3156b0));
    m_size -= a_count;
}
