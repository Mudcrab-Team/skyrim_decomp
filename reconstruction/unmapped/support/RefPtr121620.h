// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: RefPtr121620::Assign, treated as adapted: shaped like NiPointer::operator= (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:78, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RefObject121620, RefPtr121620: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

struct RefObject121620
{
    virtual ~RefObject121620();

    long refCount;  // 0x08

    void AddRef()
    {
        _InterlockedExchangeAdd(&refCount, 1);  // atomic refcount increment
    }

    void Release()
    {
        if (_InterlockedExchangeAdd(&refCount, -1) == 1)  // atomic refcount decrement
        {
            delete this;
        }
    }
};

struct RefPtr121620
{
    RefObject121620* ptr;  // 0x00

    RefPtr121620& Assign(const RefPtr121620& a_rhs);  // compared: 0x121620
};
