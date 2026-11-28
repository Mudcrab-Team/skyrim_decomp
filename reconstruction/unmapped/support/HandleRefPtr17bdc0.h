// Source exposure: binary-analysis (pinned image listing).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: HandleRefPtr17bdc0::operator=, treated as adapted: shaped like NiPointer::reset (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:140, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// HandleRefObject17bdc0, HandleRefPtr17bdc0, DeleteThis, IncRefCount, DecRefCount, refCount, reserved, ptr, rhs: GUESS(low)
#pragma once

#include <cstdint>
#include <intrin.h>

struct HandleRefObject17bdc0
{
    virtual ~HandleRefObject17bdc0();
    virtual void DeleteThis();

    long refCount;           // 0x08
    std::uint32_t reserved;  // 0x0C

    void IncRefCount()
    {
        // Reference count is updated atomically across threads.
        _InterlockedIncrement(&refCount);
    }

    void DecRefCount()
    {
        // Reference count shares the low 10 bits of the atomic word with handle flags.
        if (((_InterlockedExchangeAdd(&refCount, -1) - 1) & 0x3FF) == 0) {
            DeleteThis();
        }
    }
};
static_assert(sizeof(HandleRefObject17bdc0) == 0x10, "HandleRefObject17bdc0 size");

class HandleRefPtr17bdc0
{
public:
    HandleRefPtr17bdc0& operator=(HandleRefObject17bdc0* rhs);

private:
    HandleRefObject17bdc0* ptr;  // 0x00
};
static_assert(sizeof(HandleRefPtr17bdc0) == 0x8, "HandleRefPtr17bdc0 size");
