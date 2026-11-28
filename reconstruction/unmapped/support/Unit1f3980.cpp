// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: IntrusivePtr1f3980::Reset, RefBase1f3980::IncRef and DecRef, treated as adapted: shaped like NiPointer::reset and BSHandleRefObject::DecRefCount and BSHandleRefObject::IncRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:140, src/RE/B/BSHandleRefObject.cpp:12, src/RE/B/BSHandleRefObject.cpp:20, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1f3980 Unit1f3980::SetTarget1f3980
#include "Unit1f3980.h"

// Replaces the stored intrusive pointer, adjusting reference counts on the new and previous targets.
void Unit1f3980::SetTarget1f3980(Target1f3980* a_target)
{
    ptr.Reset(a_target);
}
