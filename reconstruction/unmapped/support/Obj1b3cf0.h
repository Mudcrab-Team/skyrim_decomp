// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: SmartPtr1b3cf0::operator=, RefBase1b3cf0::IncRef and DecRef, treated as adapted: shaped like NiPointer::operator= and BSHandleRefObject::DecRefCount and BSHandleRefObject::IncRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:78, src/RE/B/BSHandleRefObject.cpp:12, src/RE/B/BSHandleRefObject.cpp:20, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RefBase1b3cf0, Target1b3cf0, SmartPtr1b3cf0, Obj1b3cf0, Visit: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include <intrin.h>

struct RefBase1b3cf0
{
    virtual ~RefBase1b3cf0();
    virtual void DeleteThis();

    void IncRef()
    {
        // atomic intrusive reference count increment
        _InterlockedIncrement(&refCount);
    }

    void DecRef()
    {
        // atomic 10-bit intrusive reference count decrement
        if ((_InterlockedDecrement(&refCount) & 0x3FF) == 0) {
            DeleteThis();
        }
    }

    long refCount;  // 08
};

struct Target1b3cf0
{
    std::uint8_t unk00[0x20];  // 00
    RefBase1b3cf0 refBase20;   // 20
    std::uint8_t unk30[0x24];  // 30
    float x;                   // 54
    float y;                   // 58
    float z;                   // 5C
};

struct SmartPtr1b3cf0
{
    SmartPtr1b3cf0& operator=(const SmartPtr1b3cf0& a_rhs)
    {
        Target1b3cf0* rhs = a_rhs.ptr;
        Target1b3cf0* old = ptr;
        if (old != rhs) {
            if (rhs) {
                rhs->refBase20.IncRef();
            }
            ptr = rhs;
            if (old) {
                old->refBase20.DecRef();
            }
        }
        return *this;
    }

    Target1b3cf0* ptr;  // 00
};

struct Obj1b3cf0
{
    std::uint32_t Visit(const SmartPtr1b3cf0& a_entry);  // compared: 0x1b3cf0

    float x;                   // 00
    float y;                   // 04
    float z;                   // 08
    float bestDistSq;          // 0C
    SmartPtr1b3cf0* outBest;   // 10
};
