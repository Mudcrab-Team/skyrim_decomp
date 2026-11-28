// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: IntrusivePtr1f39d0::Reset, RefBase1f39d0::IncRef and DecRef, treated as adapted: shaped like NiPointer::reset and BSHandleRefObject::DecRefCount and BSHandleRefObject::IncRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:140, src/RE/B/BSHandleRefObject.cpp:12, src/RE/B/BSHandleRefObject.cpp:20, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RefBase1f39d0, PrimaryBase1f39d0, Target1f39d0, IntrusivePtr1f39d0, Unit1f39d0: GUESS(low)
// unk00, unk08, refCount, ptr, DeleteThis, IncRef, DecRef, Reset, SetTarget1f39d0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

struct PrimaryBase1f39d0
{
    virtual ~PrimaryBase1f39d0();

    std::uint8_t unk08[0x18];  // 08
};
static_assert(sizeof(PrimaryBase1f39d0) == 0x20, "PrimaryBase1f39d0 size");

struct RefBase1f39d0
{
    virtual ~RefBase1f39d0();
    virtual void DeleteThis();

    long refCount;  // 08

    void IncRef()
    {
        // Atomic intrusive reference count increment.
        _InterlockedIncrement(&refCount);
    }

    void DecRef()
    {
        // Atomic intrusive reference count decrement with bit-mask check.
        if ((_InterlockedDecrement(&refCount) & 0x3FF) == 0) {
            DeleteThis();
        }
    }
};
static_assert(offsetof(RefBase1f39d0, refCount) == 0x08, "RefBase1f39d0::refCount offset");

struct Target1f39d0 : PrimaryBase1f39d0, RefBase1f39d0
{
};

template <class T>
struct IntrusivePtr1f39d0
{
    T* ptr;  // 00

    void Reset(T* a_ptr)
    {
        T* old = ptr;
        if (old != a_ptr) {
            if (a_ptr) {
                a_ptr->IncRef();
            }
            ptr = a_ptr;
            if (old) {
                old->DecRef();
            }
        }
    }
};

struct Unit1f39d0
{
    std::uint8_t unk00[0x10];            // 00
    IntrusivePtr1f39d0<Target1f39d0> ptr; // 10

    void SetTarget1f39d0(Target1f39d0* a_target);  // compared: 0x1f39d0
};
static_assert(offsetof(Unit1f39d0, ptr) == 0x10, "Unit1f39d0::ptr offset");
