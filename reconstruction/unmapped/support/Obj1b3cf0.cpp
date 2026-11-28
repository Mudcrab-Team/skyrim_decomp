// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: SmartPtr1b3cf0::operator=, RefBase1b3cf0::IncRef and DecRef, treated as adapted: shaped like NiPointer::operator= and BSHandleRefObject::DecRefCount and BSHandleRefObject::IncRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:78, src/RE/B/BSHandleRefObject.cpp:12, src/RE/B/BSHandleRefObject.cpp:20, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x1b3cf0 Obj1b3cf0::Visit
#include "Obj1b3cf0.h"

// Updates outBest and bestDistSq when a_entry is closer to (x, y, z) than bestDistSq.
std::uint32_t Obj1b3cf0::Visit(const SmartPtr1b3cf0& a_entry)
{
    Target1b3cf0* target = a_entry.ptr;
    float dx = target->x - x;
    float dy = target->y - y;
    float dz = target->z - z;
    float distSq = dy * dy + dx * dx + dz * dz;
    if (distSq < bestDistSq) {
        bestDistSq = distSq;
        *outBest = a_entry;
    }
    return 1;
}
