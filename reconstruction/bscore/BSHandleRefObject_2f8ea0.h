// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementation using the observed cleanup and partial layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSHandleRefObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiRefObject, DeleteThis: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// refCount, ms_totalObjects: GUESS(low)
// NiRefObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <intrin.h>

class NiRefObject
{
public:
    virtual ~NiRefObject()
    {
        // Destruction decrements the shared object count atomically.
        _InterlockedDecrement(&ms_totalObjects);
    }
    virtual void DeleteThis();

protected:
    std::uint32_t refCount;
    std::uint32_t padding0C;
    static volatile long ms_totalObjects;
};

class BSHandleRefObject : public NiRefObject
{
public:
    BSHandleRefObject();
    ~BSHandleRefObject() override;
};
static_assert(sizeof(BSHandleRefObject) == 0x10, "observed allocation size");
