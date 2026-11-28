// Source exposure: binary-analysis
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: RefPtr120ad0::~RefPtr120ad0, treated as adapted: shaped like NiPointer::~NiPointer (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RefObject120ad0, RefPtr120ad0: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

struct RefObject120ad0
{
    virtual ~RefObject120ad0();

    long refCount;  // 0x08

    void Release()
    {
        if (_InterlockedExchangeAdd(&refCount, -1) == 1)  // atomic refcount decrement
        {
            delete this;
        }
    }
};

struct RefPtr120ad0
{
    RefObject120ad0* ptr;  // 0x00

    ~RefPtr120ad0();       // compared: 0x120ad0
};
