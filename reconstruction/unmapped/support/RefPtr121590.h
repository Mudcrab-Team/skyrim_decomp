// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: RefPtr121590::Assign, treated as adapted: shaped like NiPointer::operator= (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:78, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RefObject121590, RefPtr121590: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

struct RefObject121590
{
    virtual ~RefObject121590();

    long refCount;  // 0x08

    void Release()
    {
        if (_InterlockedExchangeAdd(&refCount, -1) == 1)  // atomic refcount decrement
        {
            delete this;
        }
    }
};

struct RefPtr121590
{
    RefObject121590* ptr;  // 0x00

    RefPtr121590& Assign(RefObject121590* a_ptr);  // compared: 0x121590
};
