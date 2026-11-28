// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj28e340::~Obj28e340 and RefCounted28e340::DecRef, treated as adapted: shaped like NiPointer::~NiPointer and BSHandleRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/B/BSHandleRefObject.cpp:12, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Base28e340, RefCounted28e340, Target28e340, Obj28e340: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

class Base28e340
{
public:
    virtual ~Base28e340();

    std::uint8_t unk08[0x18];  // 0x08
};

class RefCounted28e340
{
public:
    virtual ~RefCounted28e340();
    virtual void DeleteThis();

    void DecRef()
    {
        // thread-safe 10-bit reference count decrement
        if (((_InterlockedDecrement(&refCount) & 0x3FF) == 0)) {
            DeleteThis();
        }
    }

    long refCount;  // 0x08
};

class Target28e340 : public Base28e340, public RefCounted28e340
{
};

class Obj28e340
{
public:
    ~Obj28e340();

    Target28e340* ptr;  // 0x00
};

static_assert(sizeof(Base28e340) == 0x20, "Base28e340 size");
static_assert(offsetof(RefCounted28e340, refCount) == 0x08, "refCount offset");
