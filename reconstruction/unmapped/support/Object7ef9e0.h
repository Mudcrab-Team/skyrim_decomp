// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: RefPtr7ef9e0::~RefPtr7ef9e0, treated as adapted: shaped like NiPointer::~NiPointer (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RefObject7ef9e0, RefPtr7ef9e0, DeleteThis, DecRefCount, refCount, reserved, ptr, unk00, refPtr28: GUESS(low)
// Object7ef9e0: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

struct RefObject7ef9e0
{
    virtual ~RefObject7ef9e0();
    virtual void DeleteThis();

    long refCount;           // 0x08
    std::uint32_t reserved;  // 0x0C

    void DecRefCount()
    {
        // Reference count is decremented atomically across threads.
        if (_InterlockedExchangeAdd(&refCount, -1) == 1) {
            DeleteThis();
        }
    }
};
static_assert(sizeof(RefObject7ef9e0) == 0x10, "RefObject7ef9e0 size");

struct RefPtr7ef9e0
{
    RefObject7ef9e0* ptr;  // 0x00

    ~RefPtr7ef9e0()
    {
        if (ptr != nullptr) {
            ptr->DecRefCount();
        }
    }
};
static_assert(sizeof(RefPtr7ef9e0) == 0x8, "RefPtr7ef9e0 size");

class Object7ef9e0
{
public:
    ~Object7ef9e0();

    std::uint64_t unk00[5];  // 0x00
    RefPtr7ef9e0 refPtr28;   // 0x28
};
static_assert(offsetof(Object7ef9e0, refPtr28) == 0x28, "Object7ef9e0 refPtr28 offset");
