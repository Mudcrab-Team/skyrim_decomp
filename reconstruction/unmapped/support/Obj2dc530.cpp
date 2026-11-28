// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: SmartPtr2dc530::operator=, RefObj2dc530::IncRef and DecRef, treated as adapted: shaped like NiPointer::operator= and NiRefObject::IncRefCount and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:78, src/RE/N/NiRefObject.cpp:22, src/RE/N/NiRefObject.cpp:28, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2dc530 Obj2dc530::operator=
// CI hash: 0x2dc530 ??4Obj2dc530@@QEAAAEAV0@AEBV0@@Z
#include "Obj2dc530.h"

// Guess: copy-assign three intrusive smart-pointer fields and one trailing flag byte.
Obj2dc530& Obj2dc530::operator=(const Obj2dc530& a_rhs) = default;
