// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: IntrusivePtr1f3980::Reset, RefBase1f3980::IncRef and DecRef, treated as adapted: shaped like NiPointer::reset and BSHandleRefObject::DecRefCount and BSHandleRefObject::IncRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:140, src/RE/B/BSHandleRefObject.cpp:12, src/RE/B/BSHandleRefObject.cpp:20, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RefBase1f3980, PrimaryBase1f3980, Target1f3980, IntrusivePtr1f3980, Unit1f3980, SetTarget1f3980: GUESS(low)
// unk00, unk08, refCount, ptr, DeleteThis, IncRef, DecRef, Reset: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

struct PrimaryBase1f3980
{
    virtual ~PrimaryBase1f3980();

    std::uint8_t unk08[0x18];  // 08
};
static_assert(sizeof(PrimaryBase1f3980) == 0x20, "PrimaryBase1f3980 size");

struct RefBase1f3980
{
    virtual ~RefBase1f3980();
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
static_assert(offsetof(RefBase1f3980, refCount) == 0x08, "RefBase1f3980::refCount offset");

struct Target1f3980 : PrimaryBase1f3980, RefBase1f3980
{
};

template <class T>
struct IntrusivePtr1f3980
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

struct Unit1f3980
{
    std::uint64_t unk00;                 // 00
    IntrusivePtr1f3980<Target1f3980> ptr; // 08

    void SetTarget1f3980(Target1f3980* a_target);  // compared: 0x1f3980
};
static_assert(offsetof(Unit1f3980, ptr) == 0x08, "Unit1f3980::ptr offset");
