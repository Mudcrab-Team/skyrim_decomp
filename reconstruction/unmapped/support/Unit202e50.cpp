// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: IntrusivePtr202e50::~IntrusivePtr202e50, treated as adapted: shaped like NiPointer::~NiPointer and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/N/NiRefObject.cpp:28, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x202e50 Unit202e50::EraseUnordered202e50
#include "Unit202e50.h"

// Destroys the element at a_it, moves the tail element into its slot, and returns the updated iterator.
Iterator202e50 Unit202e50::EraseUnordered202e50(const Iterator202e50& a_it)
{
    const std::ptrdiff_t idx = a_it.ptr - data;
    const std::uint32_t pos = static_cast<std::uint32_t>(idx);
    const std::uint32_t remaining = header.count - pos - 1;
    const std::uint32_t moveCount = remaining < 1 ? remaining : 1;
    data[pos].~IntrusivePtr202e50();
    header.MoveTail(data, pos, header.count - moveCount, moveCount, sizeof(IntrusivePtr202e50));
    --header.count;
    return Iterator202e50(header.count == 0 ? nullptr : data + pos);
}
