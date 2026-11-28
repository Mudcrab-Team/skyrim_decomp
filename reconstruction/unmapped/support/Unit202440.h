// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: IntrusivePtr202440::~IntrusivePtr202440, treated as adapted: shaped like NiPointer::~NiPointer and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/N/NiRefObject.cpp:28, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Target202440, IntrusivePtr202440, Unit202440, DeleteThis, refCount, ptr, unk00, target: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

struct Target202440
{
    virtual ~Target202440();
    virtual void DeleteThis();

    long refCount;  // 08
};
static_assert(offsetof(Target202440, refCount) == 0x08, "Target202440::refCount offset");

struct IntrusivePtr202440
{
    Target202440* ptr;  // 00

    ~IntrusivePtr202440()
    {
        Target202440* old = ptr;
        // Atomic intrusive reference count decrement.
        if (old && _InterlockedDecrement(&old->refCount) == 0) {
            old->DeleteThis();
        }
    }
};

struct Unit202440
{
    std::uint8_t unk00[0x28];  // 00
    IntrusivePtr202440 target; // 28

    ~Unit202440();  // compared: 0x202440
};
static_assert(offsetof(Unit202440, target) == 0x28, "Unit202440::target offset");
