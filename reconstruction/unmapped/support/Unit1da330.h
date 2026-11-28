// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: RefPtr1da330::~RefPtr1da330 and HandleRefBase1da330::DecRef, treated as adapted: shaped like NiPointer::~NiPointer and BSHandleRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/B/BSHandleRefObject.cpp:12, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// PrimaryBase1da330, HandleRefBase1da330, RefObject1da330, RefPtr1da330, Unit1da330, unk08, refCount, ptr, first, second, DeleteThis, DecRef, kRefCountMask: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

struct PrimaryBase1da330
{
    virtual ~PrimaryBase1da330();
    std::uint8_t unk08[0x18];  // 08
};
static_assert(sizeof(PrimaryBase1da330) == 0x20, "PrimaryBase1da330 size");

class HandleRefBase1da330
{
public:
    virtual ~HandleRefBase1da330();
    virtual void DeleteThis();

    static constexpr std::uint32_t kRefCountMask = 0x3FF;

    void DecRef()
    {
        // Atomic reference-count release shared across engine threads.
        if ((_InterlockedDecrement(&refCount) & kRefCountMask) == 0) {
            DeleteThis();
        }
    }

    long refCount;  // 08
};
static_assert(offsetof(HandleRefBase1da330, refCount) == 0x08, "HandleRefBase1da330::refCount offset");

class RefObject1da330 : public PrimaryBase1da330, public HandleRefBase1da330
{
};

template <class T>
class RefPtr1da330
{
public:
    ~RefPtr1da330()
    {
        if (ptr) {
            ptr->DecRef();
        }
    }

    T* ptr;  // 00
};

struct Unit1da330
{
    ~Unit1da330();  // compared: 0x1da330

    RefPtr1da330<RefObject1da330> first;   // 00
    RefPtr1da330<RefObject1da330> second;  // 08
};
