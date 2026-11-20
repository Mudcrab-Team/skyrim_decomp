// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiInterpolator: EXE_RTTI
// NiInterpolator::~NiInterpolator: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiRefObject, NiObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// DeleteThis, _refCount, _pad0C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ms_totalObjects, unknown10: GUESS(low)
#pragma once

#include <cstdint>
#include <intrin.h>

class NiRefObject
{
public:
    virtual ~NiRefObject()
    {
        // Destruction atomically decrements the shared live-object count.
        _InterlockedDecrement(&ms_totalObjects);
    }
    virtual void DeleteThis();

private:
    static volatile long ms_totalObjects;
    std::uint32_t _refCount;
    std::uint32_t _pad0C;
};

class NiObject : public NiRefObject
{
public:
    ~NiObject() override = default;
};

class NiInterpolator : public NiObject
{
public:
    ~NiInterpolator() override;

private:
    std::uint8_t unknown10[0x8];
};
