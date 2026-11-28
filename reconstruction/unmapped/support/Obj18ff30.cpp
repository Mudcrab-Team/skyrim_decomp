// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: SmartPtr18ff30::Reset and RefTarget18ff30::DecRef, treated as adapted: shaped like NiPointer::TryDetach and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:182, src/RE/N/NiRefObject.cpp:28, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x18ff30 Obj18ff30::Reset
#include "Obj18ff30.h"

// Releases the held smart pointer and clears the trailing pointer fields.
void Obj18ff30::Reset()
{
    target.Reset();
    unk08 = 0;
    unk10 = 0;
}
