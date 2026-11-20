// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementation using the observed cleanup and partial layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSMultiBoundShape: EXE_RTTI
// NiRefObject, DeleteThis: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// refCount, ms_totalObjects: GUESS(low)
// flags: GUESS(low)
// NiObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
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

class NiObject : public NiRefObject
{
public:
    NiObject();
};

class BSMultiBoundShape : public NiObject
{
public:
    BSMultiBoundShape();
    ~BSMultiBoundShape() override = default;

private:
    std::uint32_t flags;
};
static_assert(sizeof(BSMultiBoundShape) == 0x18, "observed allocation size");
