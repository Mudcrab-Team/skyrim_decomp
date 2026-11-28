// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: IntrusivePtr202d90::~IntrusivePtr202d90, treated as adapted: shaped like NiPointer::~NiPointer and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/N/NiRefObject.cpp:28, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x202d90 Unit202d90::EraseUnordered202d90
#include "Unit202d90.h"

// Destroys a_count elements starting at a_index and fills the gap from the tail of the array.
void Unit202d90::EraseUnordered202d90(std::uint32_t a_index, std::uint32_t a_count)
{
    const std::uint32_t remaining = header.count - a_index - a_count;
    const std::uint32_t moveCount = remaining < a_count ? remaining : a_count;
    IntrusivePtr202d90* ptr = data + a_index;
    for (std::uint32_t i = 0; i < a_count; ++i) {
        ptr[i].~IntrusivePtr202d90();
    }

    header.MoveTail(data, a_index, header.count - moveCount, moveCount, sizeof(IntrusivePtr202d90));
    header.count -= a_count;
}
