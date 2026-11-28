// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: IntrusivePtr1f39d0::Reset, RefBase1f39d0::IncRef and DecRef, treated as adapted: shaped like NiPointer::reset and BSHandleRefObject::DecRefCount and BSHandleRefObject::IncRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:140, src/RE/B/BSHandleRefObject.cpp:12, src/RE/B/BSHandleRefObject.cpp:20, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1f39d0 Unit1f39d0::SetTarget1f39d0
#include "Unit1f39d0.h"

// Replaces the stored intrusive pointer, adjusting reference counts on the new and previous targets.
void Unit1f39d0::SetTarget1f39d0(Target1f39d0* a_target)
{
    ptr.Reset(a_target);
}
