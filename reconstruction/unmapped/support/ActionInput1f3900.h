// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: HandleRefPtr1f3900::~HandleRefPtr1f3900, treated as adapted: shaped like NiPointer::~NiPointer (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActionPrefix1f3900, HandleRefObject1f3900, ActionTarget1f3900, HandleRefPtr1f3900, ActionInput1f3900, DeleteThis, DecRefCount, unk08, refCount, reserved, ptr, first, second: GUESS(low)
#pragma once

#include <cstdint>
#include <intrin.h>

struct ActionPrefix1f3900
{
    virtual ~ActionPrefix1f3900();

    std::uint64_t unk08[3];  // 0x08
};
static_assert(sizeof(ActionPrefix1f3900) == 0x20, "ActionPrefix1f3900 size");

struct HandleRefObject1f3900
{
    virtual ~HandleRefObject1f3900();
    virtual void DeleteThis();

    long refCount;           // 0x08
    std::uint32_t reserved;  // 0x0C

    void DecRefCount()
    {
        // Reference count shares the low 10 bits of the atomic word with handle flags.
        if (((_InterlockedExchangeAdd(&refCount, -1) - 1) & 0x3FF) == 0) {
            DeleteThis();
        }
    }
};
static_assert(sizeof(HandleRefObject1f3900) == 0x10, "HandleRefObject1f3900 size");

struct ActionTarget1f3900 : ActionPrefix1f3900, HandleRefObject1f3900
{
};

template <class T>
class HandleRefPtr1f3900
{
public:
    ~HandleRefPtr1f3900()
    {
        if (ptr != nullptr) {
            ptr->DecRefCount();
        }
    }

    T* ptr;  // 0x00
};

class ActionInput1f3900
{
public:
    virtual ~ActionInput1f3900();

    HandleRefPtr1f3900<ActionTarget1f3900> first;   // 0x08
    HandleRefPtr1f3900<ActionTarget1f3900> second;  // 0x10
};
static_assert(sizeof(ActionInput1f3900) == 0x18, "ActionInput1f3900 size");
