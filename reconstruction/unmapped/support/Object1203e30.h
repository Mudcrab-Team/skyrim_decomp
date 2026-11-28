// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: RefPtr_1203e30::~RefPtr_1203e30, treated as adapted: shaped like NiPointer::~NiPointer (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RefCounted_1203e30, RefPtr_1203e30, Base1203e30, Object1203e30, refCount, ptr, unk00, resource: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

struct RefCounted_1203e30
{
    long refCount;  // 0x08

    virtual ~RefCounted_1203e30();
};
static_assert(offsetof(RefCounted_1203e30, refCount) == 0x08, "refCount offset");

struct RefPtr_1203e30
{
    RefCounted_1203e30* ptr;  // 0x00

    ~RefPtr_1203e30()
    {
        RefCounted_1203e30* current = ptr;
        if (current != nullptr) {
            // Atomically decrement the reference count and delete when the last reference drops.
            if (_InterlockedExchangeAdd(&current->refCount, -1) == 1) {
                delete current;
            }
        }
    }
};

struct Base1203e30
{
    std::uint8_t unk00[0x30];  // 0x00

    ~Base1203e30();
};
static_assert(sizeof(Base1203e30) == 0x30, "Base1203e30 size");

struct Object1203e30 : Base1203e30
{
    RefPtr_1203e30 resource;  // 0x30

    ~Object1203e30();
};
static_assert(offsetof(Object1203e30, resource) == 0x30, "resource offset");
