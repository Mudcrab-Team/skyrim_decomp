// Source exposure: binary-analysis
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: RefPtr1215e0::Clear, treated as adapted: shaped like NiPointer::TryDetach (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:182, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RefObject1215e0, RefPtr1215e0: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

struct RefObject1215e0
{
    virtual ~RefObject1215e0();

    long refCount;  // 0x08

    void Release()
    {
        if (_InterlockedExchangeAdd(&refCount, -1) == 1)  // atomic refcount decrement
        {
            delete this;
        }
    }
};

struct RefPtr1215e0
{
    RefObject1215e0* ptr;  // 0x00

    RefPtr1215e0& Clear();  // compared: 0x1215e0
};
