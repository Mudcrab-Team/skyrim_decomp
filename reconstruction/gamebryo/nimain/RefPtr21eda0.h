// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: RefPtr21eda0::operator=, treated as adapted: shaped like NiPointer::operator= and NiRefObject::IncRefCount and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:78, src/RE/N/NiRefObject.cpp:22, src/RE/N/NiRefObject.cpp:28, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RefObject21eda0, RefPtr21eda0, refCount, object: GUESS(low)
#pragma once

#include <intrin.h>

class RefObject21eda0
{
public:
    virtual ~RefObject21eda0();

    long refCount;  // 08
};

class RefPtr21eda0
{
public:
    RefPtr21eda0& operator=(const RefPtr21eda0& rhs);

    RefObject21eda0* object;  // 00
};
