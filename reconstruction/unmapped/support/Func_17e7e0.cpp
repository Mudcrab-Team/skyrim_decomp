// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: RefPtr17e7e0::~RefPtr17e7e0 and RefTarget17e7e0::DecRef, treated as adapted: shaped like NiPointer::~NiPointer and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/N/NiRefObject.cpp:28, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x17e7e0 Func_17e7e0::DestroyRange
#include "Func_17e7e0.h"

// Destroys count 0x18-byte entries starting at startIndex.
void Func_17e7e0::DestroyRange(std::uint32_t startIndex, std::uint32_t count)
{
    Entry17e7e0* base = data;
    Entry17e7e0* cur = &base[startIndex];
    for (std::uint32_t i = 0; i < count; ++i)
    {
        cur->~Entry17e7e0();
        ++cur;
    }
}
