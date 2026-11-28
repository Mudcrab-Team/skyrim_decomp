// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: SmartPtr2d1a00::~SmartPtr2d1a00 and RefCounted2d1a00::Release, treated as adapted: shaped like NiPointer::~NiPointer and BSHandleRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/B/BSHandleRefObject.cpp:12, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2d1a00 Obj2d1a00::~Obj2d1a00
#include "Obj2d1a00.h"

// Guess: release the intrusive smart-pointer member on destruction.
Obj2d1a00::~Obj2d1a00() = default;
